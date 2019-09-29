/* Main thread of the project */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "lib/exec_files.h"

int main(void)
{
    DIR *dir;
    char base_path[4096];
    char service_path[4096];
    char ext_path[4096];

    printf("lwmgmt started...\n");

    memset(base_path,'\0',sizeof(base_path));
    getcwd(base_path, 999);
    printf("the current dir is : %s\n",base_path);

    // Load services
    strcpy(service_path, base_path);
    strcat(service_path, "/service");
    exec_files(service_path);

    // Load extensions
    strcpy(ext_path, base_path);
    strcat(ext_path, "/extension");
    exec_files(ext_path);

    
    while (1) {
        printf("Main thread is working...\n");

        sleep(1);
    }

    return 0;
}
