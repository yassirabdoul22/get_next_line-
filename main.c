#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <stdio.h>

int main ()
{
    int fd = open("file.txt",O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s",str);
    free(str);
    return 0;
}

