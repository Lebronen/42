/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:12:59 by rshay             #+#    #+#             */
/*   Updated: 2022/11/15 15:36:14 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(size_t n, char *base)
{
	int	size;

	size = 1;
	n /= ft_strlen(base);
	while (n)
	{
		++size;
		n /= ft_strlen(base);
	}
	return (size);
}

static void	ft_itoa2(char *s, size_t n, int len, char *base)
{
	if (n)
	{
		s[len] = (base[n % ft_strlen(base)]);
		ft_itoa2(s, n / ft_strlen(base), len - 1, base);
	}
}

char	*ft_sizetoa(size_t n, char *base)
{
	int		size;
	char	*result;

	size = get_size(n, base);
	result = (char *)malloc((size + 1) * sizeof (*result));
	if (result != NULL)
	{
		if (n == 0)
			result[0] = '0';
		ft_itoa2(result, n, size - 1, base);
		result[size] = '\0';
	}
	return (result);
}
