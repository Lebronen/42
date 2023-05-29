/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:04:09 by rshay             #+#    #+#             */
/*   Updated: 2022/11/07 17:13:03 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((unsigned char)*s != (unsigned char)c && (unsigned char)*s)
	{
		s++;
	}
	if (!(unsigned char)*s && (unsigned char)c)
		return (NULL);
	return ((char *)s);
}
