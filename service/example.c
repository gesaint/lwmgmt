#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;

    for (i = 0; i < 5; i++) {
        printf("Example service is working...\n");
        sleep(1);
    }

    return 0;
}
