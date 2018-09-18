#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libvirt/libvirt.h>
#include "virt_server.h"
#include "vm_new.h"
#include "vm_list.h"

int main(int argc, char *argv[])
{
    // For debug
    int cond = 0;

    conn = virConnectOpen("qemu:///system");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to qemu:///system\n");
        return -1;
    }

    // Add APIs here
    switch (cond) {
        case VM_NEW:
            vm_new();
            break;
        case VM_LIST:
            vm_list();
            break;
        default:
            fprintf(stderr, "Failed to open connection to qemu:///system\n");
    }

    if (conn != NULL) {
        virConnectClose(conn);
    }

    return 0;
}
