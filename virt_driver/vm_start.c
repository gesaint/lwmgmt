#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include <libvirt/virterror.h>

int vm_start(virConnectPtr conn, const char *name)
{
    int ret;
    virDomainPtr domain = virDomainLookupByName(conn, name);

    ret = virDomainCreate(domain);
    if (ret == -1) {
        virErrorPtr error = virGetLastError();
        fprintf(stderr, "virDomainStart failed: %s!\n", error->message);
        virFreeError(error);
    }

    return ret;
}
