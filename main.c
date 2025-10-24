#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd1, fd2;
    char *line1;
    char *line2;

    fd1 = open("file.txt", O_RDONLY);
    fd2 = open("tester.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return (1);
    }

    printf("📄 Lecture alternée entre file.txt et tester.txt :\n\n");

        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        printf("%s", line1);
         printf("%s", line2);
        

}
