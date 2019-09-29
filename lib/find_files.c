#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <pthread.h>

int find_files(char *base_path, char **file_list)
{
    DIR *dir;
    struct dirent *ptr;
    char base[4096];
    char cmd[4096];
    pthread_t id;
    int ret;
    int len = 0;

    if ((dir=opendir(base_path)) == NULL)
    {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr=readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0) {    ///current dir OR parrent dir
            continue;
        } else if (ptr->d_type == 8 || ptr->d_type == 10) {   // file or link
            // printf("d_name:%s/%s\n",base_path,ptr->d_name);
            strcpy(cmd, base_path);
            strcat(cmd, "/");
            strcat(cmd, ptr->d_name);
            if(access(cmd, X_OK)!=-1) {   
                printf("path: %s\n", cmd);
                file_list[len] = malloc((strlen(cmd) + 1) * sizeof(char));
                strcpy(file_list[len++], cmd);
            }   
        }
    }

    closedir(dir);

    return len;
}
