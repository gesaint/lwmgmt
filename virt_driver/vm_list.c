#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include "virt_server.h"

void active_vm_list(int conn)
{
    int i;
    int numDomains;
    int *activeDomains;

    numDomains = virConnectNumOfDomains(conn);

    activeDomains = malloc(sizeof(int) * numDomains);
    numDomains = virConnectListDomains(conn, activeDomains, numDomains);

    printf("Active domain IDs:\n");
    for (i = 0 ; i < numDomains ; i++) {
        printf("  %d\n", activeDomains[i]);
    }

    free(activeDomains);
}
