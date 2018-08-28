#include <stdio.h>
#include <stdlib.h>
#include "xml_to_cache.h"
#include "data_cache.h"
 
int main (int argc, char *argv[])
{
    FILE * pf;
    long len;
    char *xml;
    size_t result;
    struct data_cache *cache;
    
    pf = fopen(argv[1], "rb" );
 
    fseek(pf, 0 , SEEK_END);
    len = ftell(pf);
    rewind(pf);
 
    xml = (char *)malloc(sizeof(char) * len);

    result = fread(xml, 1, len, pf);
    printf("%s", xml); 

    cache = xml_to_cache(xml);
    dump_cache(cache);
 
    fclose (pf);
    free (xml);

    return 0;
}
