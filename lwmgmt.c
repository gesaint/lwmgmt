/* Main thread of the project */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int main(void)
{
    DIR *dir;
    char base_path[4096];
    char service_path[4096];
    char ext_path[4096];
    char *service_files[4096];
    char *ext_files[4096];
    int len = 0;
    int i = 0;

    printf("lwmgmt started...\n");

    memset(base_path,'\0',sizeof(base_path));
    getcwd(base_path, 999);
    printf("the current dir is : %s\n",base_path);

    // Load services
    printf("Loading services...\n");
    strcpy(service_path, base_path);
    strcat(service_path, "/service");
    len = find_files(service_path, service_files);
    exec_files(service_files, len);

    // Load extensions
    printf("Loading extensions...\n");
    strcpy(ext_path, base_path);
    strcat(ext_path, "/extension");
    len = find_files(ext_path, ext_files);
    exec_files(ext_files, len);

    while (1) {
        printf("Main thread is working...\n");
        sleep(1);
    }

    for ( i = 0; i < len; i++) {
        free(service_files[i]);
    }

    for ( i = 0; i < len; i++) {
        free(ext_files[i]);
    }

    return 0;
}
