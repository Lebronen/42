/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:01:33 by rshay             #+#    #+#             */
/*   Updated: 2022/11/07 10:47:49 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset( void *pointer, int value, size_t count )
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = pointer;
	while (i < count)
	{
		dest[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
