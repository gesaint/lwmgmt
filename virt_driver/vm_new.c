#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include <libvirt/virterror.h>
#include "virt_server.h"
#include "vm_new.h"

int vm_new(int conn)
{
    char *buff = NULL;
    virDomainPtr dom = NULL;
    // TODO: Generate XML
    // ...

    dom = virDomainDefineXML(conn, buff);
    if (!dom) {
        virErrorPtr error = virGetLastError();
        fprintf(stderr, "virDomainDefineXML failed: %s!\n", error->message);
        virFreeError(error);

        return -1;
    }

    if (virDomainCreate(dom) < 0) {
        virErrorPtr error = virGetLastError();
        fprintf(stderr, "virDomainCreate failed: %s!\n", error->message);
        virDomainUndefine(dom);
        virFreeError(error);

        return -1;
    }

    return 0;
}
