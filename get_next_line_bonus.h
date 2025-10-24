#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 1024
#endif

# define OPEN_MAX 1024





char        *get_next_line(int fd);
size_t      ft_strlen( char *str);
char	*ft_strjoin(char *s1, char *s2);
int         ft_strchr(char *s, char c);

#endif