#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libvirt/libvirt.h>
#include "virt_conn.h"
#include "vm_list.h"
#include "vm_info.h"
#include "vm_new.h"
#include "vm_delete.h"

extern char *read_data_from_file(const char *path);

int main(int argc, char *argv[])
{
    virConnectPtr conn = NULL;
    virDomainPtr *vms = NULL;
    int num = 0;
    char *xml = NULL;

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
    // Define domain
    xml = read_data_from_file("/root/test2.xml");
    vm_new(conn, xml);
    // Verify
    inactive_vm_list(conn);
    // start domain
    vm_start(conn, "test2");
    // Verify
    active_vm_list(conn);
    // Shutdown domain
    vm_shutdown(conn, "test2");
    // Delete domain
    vm_delete(conn, "test2");
    // Verify
    inactive_vm_list(conn);
    // Disconnect
    close_conn(conn);

    free(vms);
    free(xml);

    return 0;
}
