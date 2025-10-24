/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:46:31 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/10/24 20:11:39 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *nextline(char *buffer)
{
    char *next;
    int i = 0;
    int j;

    while (buffer[i] && buffer[i] != '\n')
        i++;

    if (!buffer[i])
    {
        free(buffer);
        return NULL;
    }

    j = 0;
    next = calloc(ft_strlen(buffer) - i, sizeof(char));
    if (!next)
        return NULL;

    i++;
    while (buffer[i])
        next[j++] = buffer[i++];

    free(buffer);
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

    line = calloc(i + 2, sizeof(char));
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

    return line;
}

char *readfile(int fd, char *res)
{
    char *bufferd;
    char *temp;
    int reading;

    if (!res)
        res = calloc(1, 1);

    bufferd = calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!bufferd || !res)
        return NULL;

    reading = 1;
    while (reading != 0)
    {
        reading = read(fd, bufferd, BUFFER_SIZE);
        if (reading == -1)
        {
            free(bufferd);
            free(res);
            return NULL;
        }
        bufferd[reading] = '\0';

        temp = ft_strjoin(res, bufferd);
        free(res);
        res = temp;

        if (ft_strchr(bufferd, '\n'))
            break;
    }

    free(bufferd);
    return res;
}

char *get_next_line(int fd)
{
    static char *buffers[OPEN_MAX]; 
    char *line;

    if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
        return NULL;

    buffers[fd] = readfile(fd, buffers[fd]);
    if (!buffers[fd])
        return NULL;

    line = get_line(buffers[fd]);
    buffers[fd] = nextline(buffers[fd]);
    return line;
}
