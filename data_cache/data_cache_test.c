#include <stdio.h>
#include <stdlib.h>
#include "xml_to_cache.h"
#include "cache_to_xml.h"
#include "data_cache.h"
 
int main (int argc, char *argv[])
{
    FILE * pf;
    long len;
    char *xml;
    size_t result;
    struct data_cache *cache;
    char *output;
    
    pf = fopen(argv[1], "rb" );
 
    fseek(pf, 0 , SEEK_END);
    len = ftell(pf);
    rewind(pf);
 
    xml = (char *)malloc(sizeof(char) * len);

    result = fread(xml, 1, len, pf);
    // printf("%s", xml); 

    cache = xml_to_cache(xml);
    output = cache_to_xml(cache);
 
    fclose (pf);
    free (xml);

    return 0;
}
