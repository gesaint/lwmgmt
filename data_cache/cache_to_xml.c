#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "data_cache.h"

void node_to_xml(xmlNodePtr node, struct data_cache *cache) {
    xmlNodePtr newNode = NULL;
    struct data_cache *idx = NULL;

    if (cache) {
        if (cache->type == 0) {
            while (cache) {
                printf("*cache->name:%s\n*", cache->name);
                newNode = xmlNewChild(node, NULL, BAD_CAST cache->name, BAD_CAST cache->val);

                idx = cache->prop;
                if (idx) {
                    node_to_xml(newNode, idx);
                }

                idx = cache->child;
                if (idx) {
                    node_to_xml(newNode, idx);
                }

                cache = cache->sibling;
            }
        } else {
            while (cache) {
                xmlNewProp(node, BAD_CAST cache->name, BAD_CAST cache->val);
                cache = cache->sibling;
            }
        }
    }
}

char *cache_to_xml(struct data_cache *cache) {
    xmlDocPtr doc = NULL;
    xmlNodePtr node = NULL;
    struct data_cache *idx = NULL;
    char *ret = NULL;

    doc = xmlNewDoc(BAD_CAST "1.0");
    if (cache) {
        if (cache->name) {
            node = xmlNewNode(NULL, BAD_CAST cache->name);
            xmlDocSetRootElement(doc, node);
        }

        idx = cache->prop;
        if (idx) {
            node_to_xml(node, idx);
        }

        idx = cache->child;
        if (idx) {
            node_to_xml(node, idx);
        }
    }

    xmlBufferPtr buf = xmlBufferCreate();
    xmlNodeDump(buf, doc, node, 0, 1);
    printf("@@@@@ %s @@@@@", buf->content);

    return ret;
}
