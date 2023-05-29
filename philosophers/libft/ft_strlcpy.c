/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:08:58 by rshay             #+#    #+#             */
/*   Updated: 2022/09/03 16:53:49 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen((char *)src);
	if (i + 1 < size)
	{
		j = -1;
		while (++j < i + 1)
		{
			dst[j] = src[j];
		}
	}
	else if (size)
	{
		j = -1;
		while (++j < size - 1)
		{
			dst[j] = src[j];
		}
		dst[j] = '\0';
	}
	return (i);
}
