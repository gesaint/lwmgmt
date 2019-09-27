#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libvirt/libvirt.h>
#include <string.h>
#include "virt_conn.h"

virConnectPtr open_conn(char *ip)
{
    virConnectPtr conn = NULL;
    char uri[1024];
    strcpy(uri, "qemu+tcp://");
    strcat(uri, ip);
    strcat(uri, "/system");
    conn = virConnectOpen(uri);
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to %s\n", uri);
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
