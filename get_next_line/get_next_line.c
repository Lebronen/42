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

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*res;
	size_t		n;
	static char	*s;

	if (!fd)
			return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
			return (NULL);
	n = read(fd, buffer, BUFFER_SIZE);
	if (!n)
			return (NULL);
	res = malloc(ft_line_size(buffer) * sizeof(char) + 1);
	s = malloc((ft_strlen(buffer) - ft_line_size(buffer)) * sizeof(char) + 1);
	if (!res || !s)
			return (NULL);
	ft_strncpy(buffer, res, (size_t)ft_line_size(buffer));
	ft_strncpy(buffer + ft_line_size(buffer), s, ft_strlen(buffer) - ft_line_size(buffer));
	free(buffer);
	return (res);
}
