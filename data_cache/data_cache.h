#ifndef _DATA_CACHE_H
#define _DATA_CACHE_H

struct data_cache {
    char *name;
    char *val;
    int type;
    struct data_cache *prop;
    struct data_cache *sibling;
    struct data_cache *child;
};

struct data_cache *malloc_node_cache(void);
struct data_cache *malloc_attr_cache(void);
void dump_cache(struct data_cache *root);
#endif
