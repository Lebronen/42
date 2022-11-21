/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:29:32 by rshay             #+#    #+#             */
/*   Updated: 2022/11/16 19:13:44 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *ft_readline(int fd, char *temp, int i)
{
        char    *buffer;
        char    *str;
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!buffer)
                return (NULL);     
        str = malloc(BUFFER_SIZE * sizeof(char));
        while (!in_str(temp, '\n') && !in_str(str, '\n') && read(fd, buffer, BUFFER_SIZE))
        {
                if (i % 2 == 1)
                {
                        str = malloc((i + 1) * BUFFER_SIZE * sizeof(char) + 1);
                        ft_strncpy(str, temp, i * BUFFER_SIZE);
                        ft_strncat(str, buffer, BUFFER_SIZE);
                        free(temp);
                }
                else
                {
                        temp = malloc((i + 1) * BUFFER_SIZE * sizeof(char) + 1);
                        ft_strncpy(temp, str, i * BUFFER_SIZE);
                        ft_strncat(temp, buffer, BUFFER_SIZE);
                        free(str);
                }
                i++;
        }
        if (i % 2 == 0)
        {
                temp = malloc((i + 1) * BUFFER_SIZE * sizeof(char));
                ft_strncpy(temp, str, i * BUFFER_SIZE);
                free(str);
        }
        return (temp);
}

char    *ft_linecpy(char *temp)
{
        char    *res;

        res = malloc(1);
        if (!res)
                return (NULL);
        ft_strncpy(res, temp, ft_line_size(temp));
        return (res);
}

char    *get_next_line(int fd)
{
        static char     *temp;
        static int      ind = 0;
        char            *res;

        if (fd < 0 || BUFFER_SIZE <= 0 || ind == -1)
                return (NULL);
        if (read(fd, NULL, 0) < 0)
                return (NULL);
        if (!ind)
        {
                temp = malloc(BUFFER_SIZE * sizeof(char));
        }
        if (ind)      
                temp = ft_readline(fd, temp, 1);
        else
                temp = ft_readline(fd, temp, 0);
        res = ft_linecpy(temp);
        if (!res[0])
                ind = -1;
        else
                ind =  ft_line_size(res);
        ft_clear(temp);
        return(res);
}
        


