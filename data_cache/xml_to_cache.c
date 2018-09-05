#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "data_cache.h"

#define MAX_PATH_LEN 4096

void parseAttrs(xmlNodePtr node, struct data_cache *cache) {
    xmlAttrPtr attr = node->properties;
    int tmp_len;

    while (attr != NULL) {
        xmlChar *val = xmlGetProp(node, attr->name);
        if (val != NULL) {
            cache->name = malloc(strlen(attr->name) * sizeof(char) + 1);
            strcpy(cache->name, attr->name);
            printf("Attr name is %s.\n", cache->name);
            cache->val = malloc(strlen(val) * sizeof(char) + 1);
            strcpy(cache->val, val);
            printf("Attr value is %s.\n", cache->val);

            xmlFree(val);
        }
        attr = attr->next; 
        if (attr) {
            cache->sibling = malloc_attr_cache();
            cache = cache->sibling;
        }
    }

    return;
}

void parseNode(xmlDocPtr doc, xmlNodePtr node, struct data_cache *cache) {
    xmlChar *val;
    int tmp_len;
    if (node->type != XML_ELEMENT_NODE)
        return;

    if (node->name) {
        cache->name = malloc(strlen(node->name) * sizeof(char) + 1);
        strcpy(cache->name, node->name);
        printf("Node name is %s.\n", cache->name);
    }

    val = xmlNodeListGetString(doc, node->xmlChildrenNode, 1);
    if (val) {
        cache->val = malloc(strlen(val) * sizeof(char) + 1);
        strcpy(cache->val, val);
        printf("Node value is %s.\n", cache->val);

        xmlFree(val);
    }

    if (node->properties) {
        cache->prop = malloc_attr_cache();
        parseAttrs(node, cache->prop);
    }

    node = node->children;
    if (node) {
        cache->child = malloc_node_cache();
        cache = cache->child;
    }

    while (node) {
        parseNode(doc, node, cache);

        node = node->next;

        if (node) {
            cache->sibling = malloc_node_cache();
            cache = cache->sibling;
        }
    }

    return;
}

struct data_cache *xml_to_cache(char *xml) {
    xmlDocPtr doc;
    xmlNodePtr cur;
    char path[MAX_PATH_LEN];
    struct data_cache *root;

    doc = xmlParseDoc(xml);

    cur = xmlDocGetRootElement(doc);
    if (cur) {
        root = malloc_node_cache();
        parseNode(doc, cur, root);
        dump_cache(root);
    } else {
        root = NULL;
    }

    xmlFreeDoc(doc);

    return root;
}
