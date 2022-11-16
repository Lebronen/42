/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:25:55 by rshay             #+#    #+#             */
/*   Updated: 2022/11/08 14:26:49 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordlen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && *(str + i) != c)
		i++;
	return (i);
}

int	ft_wordcount(char const *str, char c)
{
	int	i;
	int	w;

	w = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		i = ft_wordlen(str, c);
		str += i;
		if (i)
			w++;
	}
	return (w);
}

char	*ft_wordcpy(char const *src, int n)
{
	char	*dest;

	dest = malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		size;
	int		i;
	int		n;

	size = ft_wordcount(s, c);
	t = malloc((size + 1) * sizeof(char *));
	if (!t)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		n = ft_wordlen(s, c);
		t[i] = ft_wordcpy(s, n);
		if (!(t[i]))
			return (NULL);
		s += n;
	}
	t[size] = 0;
	return (t);
}
