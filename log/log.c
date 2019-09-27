# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "log.h"
// # include "write_data_to_file.h"

void lw_init(void)
{
    char cmd[CMD_LEN];
    char full_path[PATH_LEN];
    FULL_PATH(full_path);

    strcpy(cmd, "mkdir -p ");
    strcat(cmd, LOG_PATH);
    system(cmd);

    strcpy(cmd, "touch ");
    strcat(cmd, full_path);
    system(cmd);
}

void lw_debug(char *str)
{
    char full_path[PATH_LEN];
    FULL_PATH(full_path);

    write_data_to_file(full_path, "[DEBUG] ");
    write_data_to_file(full_path, str);
    write_data_to_file(full_path, "\n");
}

void lw_info(char *str)
{
    char full_path[PATH_LEN];
    FULL_PATH(full_path);

    write_data_to_file(full_path, "[INFO] ");
    write_data_to_file(full_path, str);
    write_data_to_file(full_path, "\n");
}

void lw_warn(char *str)
{
    char full_path[PATH_LEN];
    FULL_PATH(full_path);

    write_data_to_file(full_path, "[WARN] ");
    write_data_to_file(full_path, str);
    write_data_to_file(full_path, "\n");
}

void lw_err(char *str)
{
    char full_path[PATH_LEN];
    FULL_PATH(full_path);

    write_data_to_file(full_path, "[ERROR] ");
    write_data_to_file(full_path, str);
    write_data_to_file(full_path, "\n");
}

void lw_log(int level, char *str)
{
    if (level == DEBUG) {
        lw_debug(str);
    } else if (level == INFO) {
        lw_info(str);
    } else if (level == WARN) {
        lw_warn(str);
    } else if (level == ERR) {
        lw_err(str);
    } else {
        lw_err("level error");
    }
}

void lw_clear(void)
{
    char cmd[CMD_LEN];

    strcpy(cmd, "rm -rf ");
    strcat(cmd, LOG_PATH);
    system(cmd);
}
