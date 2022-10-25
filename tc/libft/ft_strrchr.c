/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:56:01 by rshay             #+#    #+#             */
/*   Updated: 2022/09/02 16:58:12 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	max;

	i = 0;
	max = -1;
	while (s[i])
	{
		if (s[i] == c)
			max = i;
		i++;
	}
	if (max == -1)
		return (NULL);
	s += max;
	return ((char *)s);
}
