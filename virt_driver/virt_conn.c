#include <libvirt/libvirt.h>
#include "virt_conn.h"


int open_conn(void)
{
    virConnectPtr conn = NULL;
    conn = virConnectOpen("qemu:///system");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to qemu:///system\n");
        return -1;
    }

    return conn;
}

void close_conn(int conn)
{
    if (conn != NULL) {
        virConnectClose(conn);
    }
}
