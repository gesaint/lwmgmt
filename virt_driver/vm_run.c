#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include <libvirt/virterror.h>

int vm_run(int conn, const char *xmlconfig)
{
    virDomainPtr dom;

    dom = virConnectCreateXML(conn, xmlconfig, 0);

    if (!dom) {
        fprintf(stderr, "Domain creation failed");
        return -1;
    }

    fprintf(stderr, "Guest %s has booted", virDomainName(dom));
    virDomainFree(dom);
}
