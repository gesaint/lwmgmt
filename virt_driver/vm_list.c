#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include "virt_server.h"

void vm_list(int conn)
{
    virtDomainPtr *allDomains;
    int numDomains = 0;
    int numActiveDomains, numInactiveDomains;
    char *inactiveDomains;
    int *activeDomains;
    int i;

    numActiveDomains = virConnectNumOfDomains(conn);
    numInactiveDomains = virConnectNumOfDefinedDomains(conn);

    allDomains = malloc(sizeof(virDomainPtr) * numActiveDomains + numInactiveDomains);
    inactiveDomains = malloc(sizeof(char *) * numActiveDomains);
    activeDomains = malloc(sizeof(int) * numInactiveDomains);

    numActiveDomains = virConnectListDomains(conn, activeDomains, numActiveDomains);
    numInactiveDomains = virConnectListDomains(conn, inactiveDomains, numInactiveDomains);

    for (i = 0; i < numActiveDomains; i++) {
        allDomains[numDomains] = virDomainLookupByID(activeDomains[i]);
        numDomains++;
    }

    for (i = 0; i < numInactiveDomains; i++) {
        allDomains[numDomains] = virDomainLookupByName(inactiveDomains[i]);
        free(inactiveDomains[i]);
        numDomains++;
    }

    free(activeDomains);
    free(inactiveDomains);
}
