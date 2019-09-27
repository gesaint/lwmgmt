#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>

char *read_data_from_file(const char *path)
{
    char *buf = malloc(16384 * sizeof(char));
    char *tmp = buf;
    int len = 0;

    int fd = open(path, O_RDONLY);
    if(fd==-1) {
    	printf("error is %s\n",strerror(errno));
    }

    do {
        len = read(fd, tmp, sizeof(buf));
        tmp += len;
    } while (len > 0);
    *tmp = '\0';

    close(fd);

    return buf;
}
