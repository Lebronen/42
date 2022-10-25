/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:49:17 by rshay             #+#    #+#             */
/*   Updated: 2022/09/03 16:51:50 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s1 + i == *(unsigned char *)s2 + i)
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	i++;
	}
	return (0);
}
