# include <stdio.h>
# include <stdlib.h>
# include "logs.h"

int log_test(void)
{
    printf("Log test\n");

    // Init log
    lw_init();

    // print log
    lw_log(DEBUG, "debug log test.");
    lw_log(INFO, "info log test.");
    lw_log(WARN, "warn log test.");
    lw_log(ERR, "err log test.");

    // verify log
    system("cat /var/log/lwmgmt/lwmgmt.log");

    // clear log
    lw_clear();

    return 0;
}
