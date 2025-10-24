#include "get_next_line.h"
void ft_free(char *fr)
{
    if (fr)
        free(fr);
    return;
}
char *nextline(char *buffer)
{
    char *next;
    int i = 0;
    int j;

    while (buffer[i] && buffer[i] != '\n')
        i++;

    if (!buffer[i])
    {
        ft_free(buffer);
        return NULL;
    }

    j = 0;
    next = calloc(ft_strlen(buffer) - i + 1, sizeof(char));
    if (!next)
        return NULL;

    i++;
    while (buffer[i])
        next[j++] = buffer[i++];

    ft_free(buffer);
    return next;
}

char *get_line(char *buffer)
{
    char *line;
    int i = 0;

    if (!buffer[i])
        return NULL;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        line = calloc(i + 2, sizeof(char));
    else
        line = calloc(i + 1, sizeof(char));
    if (!line)
        return NULL;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }

    if (buffer[i] && buffer[i] == '\n')
        line[i++] = '\n';
    line[i++] = 0;

    return line;
}

char *readfile(int fd, char *res)
{
    char *bufferd;
    int rd;

    if (!res)
        res = calloc(1, 1);
    bufferd = calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!bufferd || !res)
        return NULL;

    rd = 1;
    while (rd > 0 && !ft_strchr(res, '\n'))
    {
        rd = read(fd, bufferd, BUFFER_SIZE);
        if (rd < 0)
            return (ft_free(bufferd), ft_free(res), NULL);
        if (rd == 0)
            break;
        bufferd[rd] = '\0';
        char *tmp = ft_strjoin(res, bufferd);
        ft_free(res);
        res = tmp;
        if (!res)
            return (ft_free(bufferd), NULL);
    }
    ft_free(bufferd);
    return res;
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    buffer = readfile(fd, buffer);
    if (!buffer)
        return NULL;
    line = get_line(buffer);
    buffer = nextline(buffer);
    return line;
}
