#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_cache.h"
#include "cache_to_json.h"

#define BUF_LEN 16384

char *push_chr(char *pos, char chr) {
    *pos = chr;
    pos++;

    return pos;
}

void push_end(char *pos) {
    *pos = '\0';
}

char *push_blank(char *pos, int cnt) {
    int i = 0;

    for (i = 0; i < cnt; i++) {
        pos = push_chr(pos, ' ');
    }

    return pos;
}

char *push_enter(char *pos) {
    return push_chr(pos, '\n');
}

char *push_str(char *pos, char *src) {
    // "string"
    pos = push_chr(pos, '\"');
    strcpy(pos, src);
    pos += strlen(src);
    pos = push_chr(pos, '\"');

    return pos;
}

char *push_colon(char *pos) {
    pos = push_chr(pos, ':');
    pos = push_blank(pos, 1);

    return pos;
}

char *new_prop(struct data_cache *node, char *pos, int level) {
    struct data_cache *idx = node;
    int len;
    char *tmp;

    while (idx) {
        printf("############# prop: %s ##############\n", idx->name);
        // "key": "val"
        pos = push_blank(pos, 2 * level);
        len = strlen(idx->name);
        tmp = malloc((len + 1) * sizeof(char));
        *tmp = '-';
        strcpy(tmp + 1, idx->name);
        pos = push_str(pos, tmp);
        free(tmp);
        pos = push_colon(pos);
        pos = push_str(pos, idx->val);

        // Check if need ',' or not
        idx = idx->sibling;
        if (idx) {
            pos = push_chr(pos, ',');
        }
        pos = push_enter(pos);
    }

    return pos;
}

char *new_obj(struct data_cache *node, char *pos, int level) {
    struct data_cache *idx = node;

    if (node->name == NULL) {
        return pos;
    }

    printf("############# node ptr: %p ##############\n", idx);
    printf("############# node: %s ##############\n", idx->name);
    printf("############# node: %s ##############\n", idx->val);
    // "xxx": {
    pos = push_blank(pos, 2 * level);
    pos = push_str(pos, node->name);
    pos = push_colon(pos);
    pos = push_chr(pos, '{');
    pos = push_enter(pos); 

    level++;

    // Properties
    if (idx->prop) {
        pos = new_prop(idx->prop, pos, level);
        if ((idx->val && !strchr(idx->val, '\n')) || idx->child) {
            // Workaround here, swallow an enter char and make up comma
            pos--;
            pos = push_chr(pos, ',');
            pos = push_enter(pos);
        }
    }

    // Value
    if (idx->val && !strchr(idx->val, '\n')) {
        // "#text": "val"
        pos = push_blank(pos, 2 * level);
        pos = push_str(pos, "#text");
        pos = push_colon(pos);
        pos = push_str(pos, idx->val);

        if (idx->child && idx->child->name) {
            pos = push_chr(pos, ',');
        }
        pos = push_enter(pos);
    }
    
    // Subnode
    idx = idx->child;
    if (idx) {
        printf("Subnode, ptr=%p\n", idx->child);
        while (idx) {
            pos = new_obj(idx, pos, level);
            idx = idx->sibling;
        }
    }

    // } or },
    level--;
    pos = push_blank(pos, 2 * level);
    pos = push_chr(pos, '}');

    if (node->sibling && node->sibling->name) {
        pos = push_chr(pos, ',');
    }
    pos = push_enter(pos);

    return pos;
}

// Main function
char *cache_to_json(struct data_cache *node) {
    char *ret = malloc(BUF_LEN * sizeof(char));
    char *pos = ret;
    int level = 0;

    // ret string
    pos = push_chr(pos, '{');
    pos = push_enter(pos);

    if (node) {
        level++;
        pos = new_obj(node, pos, level);
    }

    pos = push_chr(pos, '}');
    push_end(pos);

    printf("############ %d ###############\n", pos - ret);

    return ret;
}
