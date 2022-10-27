/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:51:33 by rshay             #+#    #+#             */
/*   Updated: 2022/09/02 16:53:05 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	if (!str || !sub)
		return (NULL);
	if (!sub || !sub[0])
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && sub[j] && i + j < len && str[i + j] == sub[j])
			j++;
		if (!sub[j])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
