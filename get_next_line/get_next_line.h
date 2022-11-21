/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:11:00 by rshay             #+#    #+#             */
/*   Updated: 2022/11/16 19:15:42 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
        void                    *content;
        struct s_list   *next;
}                               t_list;

char    *get_next_line(int fd);
int             ft_line_size(char *s);
char    *ft_strncat(char *dest, char *src, int n);
char    *ft_clear(char *str);
int             in_str(char *str, char c);
char    *ft_strncpy(char *dst, char *src, int n);

#endif
