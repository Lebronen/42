/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:12:59 by rshay             #+#    #+#             */
/*   Updated: 2022/11/14 14:21:45 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		++size;
	n /= 10;
	while (n)
	{
		++size;
		n /= 10;
	}
	return (size);
}

static void	ft_itoa2(char *s, int n, int len)
{
	if (n)
	{
		s[len] = ft_abs(n % 10) + 48;
		ft_itoa2(s, n / 10, len - 1);
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	size = get_size(n);
	result = (char *)malloc((size + 1) * sizeof (*result));
	if (result != NULL)
	{
		if (n < 0)
			result[0] = '-';
		else if (n == 0)
			result[0] = '0';
		ft_itoa2(result, n, size - 1);
		result[size] = '\0';
	}
	return (result);
}
