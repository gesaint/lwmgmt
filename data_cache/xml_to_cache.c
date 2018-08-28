#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#define MAX_PATH_LEN 4096

void parseAttrs(xmlNodePtr node, char *path, int p_len) {
    xmlAttrPtr attr = node->properties;
    int tmp_len;

    while (attr != NULL) {
        xmlChar *val = xmlGetProp(node, attr->name);
        if (val != NULL) {
            path[p_len] = '%';
            tmp_len = p_len + 1;
            path[tmp_len] = '\0';
            strcat(path, attr->name);
            tmp_len += strlen(attr->name);

            printf("Attr name is %s.\n", attr->name);
            printf("Attr value is %s.\n", val);
            printf("Path is %s.\n", path);

            xmlFree(val);
        }

        attr = attr->next; 
    }

    return;
}

void parseNode(xmlDocPtr doc, xmlNodePtr node, char *path, int p_len) {
    xmlChar *val;
    int tmp_len;

    while (node != NULL) {
        val = xmlNodeListGetString(doc, node->xmlChildrenNode, 1);
        if (val != NULL) {
            path[p_len] = '$';
            tmp_len = p_len + 1;
            path[tmp_len] = '\0';
            strcat(path, node->name);
            tmp_len += strlen(node->name);

            printf("Node name is %s.\n", node->name);
            printf("Node value is %s.\n", val);
            printf("Path is %s.\n", path);

            xmlFree(val);

            parseAttrs(node, path, tmp_len);
            parseNode(doc, node->xmlChildrenNode, path, tmp_len);
        }

        node = node->next;
    }

    return;
}

void parseXml(char *docName) {
    xmlDocPtr doc;
    xmlNodePtr cur;
    char path[MAX_PATH_LEN];

    doc = xmlParseFile(docName);

    cur = xmlDocGetRootElement(doc);

    parseNode(doc, cur, path, 0);

    xmlFreeDoc(doc);

    return;
}

int main(int argc, char **argv) {
    char *docName;

    docName = argv[1];

    parseXml(docName);

    return 0;
}
