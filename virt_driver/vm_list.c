#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>

void active_vm_list(virConnectPtr conn)
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

void inactive_vm_list(virConnectPtr conn)
{
    int i;
    int numDomains;
    char **inactiveDomains;

    numDomains = virConnectNumOfDefinedDomains(conn);

    inactiveDomains = malloc(sizeof(char *) * numDomains);
    numDomains = virConnectListDefinedDomains(conn, inactiveDomains, numDomains);

    printf("Inactive domain names:\n");
    for (i = 0 ; i < numDomains ; i++) {
        printf("  %s\n", inactiveDomains[i]);
        free(inactiveDomains[i]);
    }
    free(inactiveDomains);
}
