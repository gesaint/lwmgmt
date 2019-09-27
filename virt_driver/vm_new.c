#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include <libvirt/virterror.h>

int vm_new(int conn, const char *xml)
{
    virDomainPtr dom = NULL;

    dom = virDomainDefineXML(conn, xml);
    if (!dom) {
        virErrorPtr error = virGetLastError();
        fprintf(stderr, "virDomainDefineXML failed: %s!\n", error->message);
        virFreeError(error);

        return -1;
    }

    return 0;
}
