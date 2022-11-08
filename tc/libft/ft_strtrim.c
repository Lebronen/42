/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:54:51 by rshay             #+#    #+#             */
/*   Updated: 2022/11/08 13:53:16 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_instr(char c, char const *str)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (ft_instr(s1[i], set) && s1[i])
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (ft_instr(s1[j], set) && j)
		j--;
	if (i > j)
		return 0;
	s2 = (char *)malloc((j - i + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		s2[k] = s1[i];
		i++;
		k++;
	}
	return (s2);
}
