/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:46:31 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/10/24 21:03:27 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char *fr)
{
	if (fr)
		free(fr);
}

char	*nextline(char *buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free(buffer), NULL);
	next = calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	ft_free(buffer);
	return (next);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = calloc(i + 2, sizeof(char));
	else
		line = calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*readfile(int fd, char *res)
{
	char	*bufferd;
	char	*tmp;
	int		rd;

	if (!res)
		res = calloc(1, 1);
	bufferd = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!bufferd)
		return (NULL);
	rd = 1;
	while (rd > 0 && !ft_strchr(res, '\n'))
	{
		rd = read(fd, bufferd, BUFFER_SIZE);
		if (rd < 0)
			return (ft_free(bufferd), ft_free(res), NULL);
		if (rd == 0)
			break ;
		bufferd[rd] = '\0';
		tmp = ft_strjoin(res, bufferd);
		ft_free(res);
		res = tmp;
		if (!res)
			return (ft_free(bufferd), NULL);
	}
	ft_free(bufferd);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffers[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffers[fd] = readfile(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = get_line(buffers[fd]);
	buffers[fd] = nextline(buffers[fd]);
	return (line);
}
