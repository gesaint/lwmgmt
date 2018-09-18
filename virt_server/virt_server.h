#ifndef VIRT_SERVER_H_
#define VIRT_SERVER_H_

#include <libvirt/libvirt.h>

#define VM_LIST 0
#define VM_NEW 1

static virConnectPtr conn = NULL;
static virDomainPtr dom = NULL;

#endif
