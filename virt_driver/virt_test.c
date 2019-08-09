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

    // Add APIs here
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


    return 0;
}
