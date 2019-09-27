# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "log.h"

int main(int argc, char *argv[])
{
    // Init log file
    lw_init();
    sleep(1);

    // print log
    lw_log(DEBUG, "debug log test.");
    lw_log(INFO, "info log test.");
    lw_log(WARN, "warn log test.");
    lw_log(ERR, "err log test.");

    // verify log
    sleep(1);
    system("cat /var/log/lwmgmt/lwmgmt.log");
    sleep(1);

    // clear log
    lw_clear();

    return 0;
}
