/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:56:01 by rshay             #+#    #+#             */
/*   Updated: 2022/11/07 17:45:56 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	max;

	i = 0;
	max = -1;
	while ((unsigned char)s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			max = i;
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		max = i;
	if (max == -1)
		return (NULL);
	s += max;
	return ((char *)s);
}
