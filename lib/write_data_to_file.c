#include <stdio.h>
#include <string.h>
#include "write_data_to_file.h"
 
int write_data_to_file(const char *path, char *str)
{
	FILE *fd = fopen(path, "a+");
	if (fd == NULL) 
	{
		printf("fd is NULL and open file fail.\n");
	}

	if (str && str[0] != '\0') 
	{
		fwrite(str, strlen(str), 1, fd);
	}

	fclose(fd);

        return 0;
}
