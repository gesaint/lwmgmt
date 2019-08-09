#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libvirt/libvirt.h>
#include "virt_conn.h"

virConnectPtr open_conn(void)
{
    virConnectPtr conn = NULL;
    conn = virConnectOpen("qemu:///system");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to qemu:///system\n");
        return NULL;
    }

    return conn;
}

void close_conn(virConnectPtr conn)
{
    if (conn != NULL) {
        virConnectClose(conn);
    }
}
