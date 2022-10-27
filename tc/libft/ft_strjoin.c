/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:29:26 by rshay             #+#    #+#             */
/*   Updated: 2022/09/02 18:52:29 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		a;
	int		b;

	a = ft_strlen((char *)s1);
	b = ft_strlen((char *)s2);
	s3 = (char *)malloc((a + b) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < a)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < b)
	{
		s3[i + a] = s2[i];
		i++;
	}
	return (s3);
}
