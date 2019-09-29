#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int exec_files(char **file_list, int len)
{
    pthread_t id;
    int ret;
    int i;

    for (i = 0; i < len; i++) {
        printf("exec_file: %s\n", file_list[i]);
        ret = pthread_create(&id, NULL, (void *)system, (void *)(file_list[i]));
        if (ret != 0) {
            printf("Create pthread error.\n");
            exit(1);
        }
    }

    return 0;
}
