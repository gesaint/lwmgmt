#include <stdio.h>
#include <stdlib.h>
#include "data_cache.h"

struct data_cache *malloc_cache(int type) {
    struct data_cache *cache = malloc(sizeof(struct data_cache));
    cache->name = NULL;
    cache->val = NULL;
    cache->type = type;
    cache->prop = NULL;
    cache->sibling = NULL;
    cache->child = NULL;

    return cache;
}

struct data_cache *malloc_node_cache(void) {
    return malloc_cache(0);
}

struct data_cache *malloc_attr_cache(void) {
    return malloc_cache(1);
}

void dump_cache(struct data_cache *cache) {
    if (cache)  {
        printf("Type: %d\n", cache->type);
        printf("Name: %s\n", cache->name);
        printf("Value: %s\n", cache->val);

        if (cache->prop) {
            printf("===== Props =====\n");
            dump_cache(cache->prop);
            printf("===== End Props =====\n");
        }

        if (cache->sibling) {
            printf("===== Siblings =====\n");
            dump_cache(cache->sibling);
            printf("===== End Siblings =====\n");
        }

        if (cache->child) {
            printf("===== Children =====\n");
            dump_cache(cache->child);
            printf("===== End Children =====\n");
        }
    }
}
