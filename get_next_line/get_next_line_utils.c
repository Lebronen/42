/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:23:21 by rshay             #+#    #+#             */
/*   Updated: 2022/11/16 19:15:20 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_clear(char *str)
{
	
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = ft_line_size(str);
	while (str[i])
	{
		i++;
	}
	i -= x;
	while (j < i)
	{
		str[j] = str[x];
		x++;
		j++;
	}
	str[j] = '\0';
	return (str);

}

int	ft_line_size(char	*s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	if (s[i] == '\n')
		return (i + 1);
	return (i);
	
}

char	*ft_strncat(char *dst, char *src, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
	{
		i++;
	}
	while (j < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

int		in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

