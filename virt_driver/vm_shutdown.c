#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include <libvirt/virterror.h>

int vm_delete(virConnectPtr conn, const char *name)
{
    int ret;
    virDomainPtr domain = virDomainLookupByName(conn, name);

    ret = virDomainDestroy(domain);
    if (ret == -1) {
        virErrorPtr error = virGetLastError();
        fprintf(stderr, "virDomainDestroy failed: %s!\n", error->message);
        virFreeError(error);
    }

    return ret;
}
