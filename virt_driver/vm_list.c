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

int vm_list(virConnectPtr conn, virDomainPtr **vms)
{
    virDomainPtr *allDomains;
    int numDomains = 0;
    int numActiveDomains, numInactiveDomains;
    char **inactiveDomains;
    int *activeDomains;
    int i;

    numActiveDomains = virConnectNumOfDomains(conn);
    numInactiveDomains = virConnectNumOfDefinedDomains(conn);

    allDomains = malloc(sizeof(virDomainPtr) *
        (numActiveDomains + numInactiveDomains));
    inactiveDomains = malloc(sizeof(char *) * numInactiveDomains);
    activeDomains = malloc(sizeof(int) * numActiveDomains);

    numActiveDomains = virConnectListDomains(conn,
        activeDomains,
        numActiveDomains);
    numInactiveDomains = virConnectListDefinedDomains(conn,
        inactiveDomains,
        numInactiveDomains);

    for (i = 0 ; i < numActiveDomains ; i++) {
        allDomains[numDomains] = virDomainLookupByID(conn, activeDomains[i]);
        numDomains++;
    }

    for (i = 0 ; i < numInactiveDomains ; i++) {
        allDomains[numDomains] = virDomainLookupByName(conn, inactiveDomains[i]);
        free(inactiveDomains[i]);
        numDomains++;
    }

    free(activeDomains);
    free(inactiveDomains);

    *vms = allDomains;

    return numDomains;
}
