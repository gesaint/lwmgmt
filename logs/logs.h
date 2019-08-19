#ifndef __LOGS_H__
#define __LOGS_H__

#define LOG_PATH "/var/log/lwmgmt/"
#define LOG_FILE "lwmgmt.log"
#define FULL_PATH(x) do { \
                         strcpy(x, LOG_PATH); \
                         strcat(x, LOG_FILE); \
                     } while (0)
#define CMD_LEN 256
#define PATH_LEN 256

#define DEBUG     0x1
#define INFO      0x2
#define WARN      0x4
#define ERR       0x8

void lw_init(void);
void lw_log(int level, char *str);
void lw_clear(void);

#endif
