#ifndef VM_LIST_H_
#define VM_LIST_H_

void active_vm_list(virConnectPtr conn);
void inactive_vm_list(virConnectPtr conn);
int vm_list(virConnectPtr conn, virDomainPtr **vms);

#endif
