#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libvirt/libvirt.h>
#include "virt_conn.h"
#include "vm_list.h"
#include "vm_info.h"

int main(int argc, char *argv[])
{
    virConnectPtr conn = NULL;
    virDomainPtr *vms = NULL;
    int num = 0;

    // Establish connection
    conn = open_conn("10.110.129.20");
    // List active domains
    active_vm_list(conn);
    // List inactive domains
    inactive_vm_list(conn);
    // List all domains
    num = vm_list(conn, &vms);
    // Get domains info
    vm_info(vms, num);
    // Disconnect
    close_conn(conn);

    free(vms);

    return 0;
}
