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

char    *get_next_line(int fd)
{
        char            *buffer;
        static char     temp[150];
        static int      ind = 0;
        char            *str;

        if (fd < 0 || BUFFER_SIZE <= 0 || ind == -1)
                return (NULL);
        buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
        if (!buffer)
                return (NULL);
        if (ind == 0)
                temp[0] = '\0';
        while (!in_str(temp, '\n') && read(fd, buffer, BUFFER_SIZE))
        {
                ft_strncat(temp, buffer, BUFFER_SIZE);
        }
        if (!in_str(temp, '\n'))
                ind = -1;
        else
                ind++;
        str = malloc(ft_line_size(temp) * sizeof(char) + 1);
        if (!str)
                return (NULL);

        str = ft_strncpy(str, temp, ft_line_size(temp));
        ft_clear(temp);
        free(buffer);
        return (str);
}

