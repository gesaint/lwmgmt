#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libvirt/libvirt.h>
#include "virt_conn.h"

int main(int argc, char *argv[])
{
    virConnectPtr conn = NULL;
    // int cond = 0;

    conn = open_conn();
    close_conn(conn);

    // Add APIs here
    /*
    switch (cond) {
        case VM_NEW:
            vm_new(conn);
            break;
        case VM_LIST:
            vm_list(conn);
            break;
        default:
            fprintf(stderr, "Failed to open connection to qemu:///system\n");
    }
    */

    return 0;
}
