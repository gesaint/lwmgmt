#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>

void vm_info(virDomainPtr *allDomains, int num)
{
    virDomainInfoPtr domaininfo;     
    int idx = 0;
    for (idx = 0; idx < num; idx++) {
        domaininfo = malloc(sizeof(virDomainInfo)* 1);  

        virDomainGetInfo(allDomains[idx] , domaininfo);  
        printf("State:%d    ",(*domaininfo).state);  
        printf("Maxmem:%ld    ",((*domaininfo).maxMem)/1024);  
        printf("Mem:%ld   ",((*domaininfo).memory)/1024);  
        printf("vCPU:%d   ",(*domaininfo).nrVirtCpu);  
        printf("CPU time:%lld   ",(*domaininfo).cpuTime);  
        printf("\n");

        free(domaininfo);
    }
}
