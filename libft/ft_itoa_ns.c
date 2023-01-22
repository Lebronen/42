/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:12:59 by rshay             #+#    #+#             */
/*   Updated: 2023/01/20 21:04:01 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 1;
	n /= 10;
	while (n)
	{
		++size;
		n /= 10;
	}
	return (size);
}

static void	ft_itoa2(char *s, unsigned int n, int len)
{
	if (n)
	{
		s[len] = (n % 10) + 48;
		ft_itoa2(s, n / 10, len - 1);
	}
}

char	*ft_itoa_ns(unsigned int n)
{
	int		size;
	char	*result;

	size = get_size(n);
	result = (char *)malloc((size + 1) * sizeof (*result));
	if (result != NULL)
	{
		if (n == 0)
			result[0] = '0';
		ft_itoa2(result, n, size - 1);
		result[size] = '\0';
	}
	return (result);
}
