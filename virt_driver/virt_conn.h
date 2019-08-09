#ifndef __VIRT_CONN_H__
#define __VIRT_CONN_H__

virConnectPtr open_conn(void);
void close_conn(virConnectPtr conn);

#endif
