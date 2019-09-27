#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <libvirt/libvirt.h>
#include "virt_conn.h"
#include "vm_list.h"

int main(int argc, char *argv[])
{
    virConnectPtr conn = NULL;

    conn = open_conn("10.110.129.20");
    active_vm_list(conn);
    inactive_vm_list(conn);
    close_conn(conn);

    return 0;
}
