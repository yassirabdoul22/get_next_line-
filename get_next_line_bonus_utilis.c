/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utilis.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:44:41 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/10/24 17:36:35 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

int	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

size_t  ft_strlen(char *s)
{
    size_t  i;
    
    i = 0;
    while(s[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *s1,char *s2)
{
    char *res;
    size_t  i;
    size_t  j;
    if(!s2)
    {
        return NULL;
    }
    if(!s1)
    {
        res = malloc(ft_strlen(s2)+1);
        if(!res)
            return NULL;
        i  = 0;
        while(s2[i])
        {
            res[i]=s2[i];
            i++;
        }
        res[i]='\0';
        return res;
    }
    res=malloc((ft_strlen(s1)+ft_strlen(s2))+1);
    if(!res)
        return NULL;
    i = 0;
    while(s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    j = 0;
    while(s2[j])
    {
        res[i++]=s2[j++];
    }
    res[i]='\0';
    return res;
}






