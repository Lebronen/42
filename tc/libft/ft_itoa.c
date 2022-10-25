/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:28:20 by rshay             #+#    #+#             */
/*   Updated: 2022/09/03 16:41:53 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(long long int n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (0);
	else
		return (1 + ft_nblen(n / 10));
}

char	*ft_itoa(int n)
{
	char			*res;
	int				x;
	int				neg;
	long long int	y;

	y = n;
	neg = (y < 0);
	x = ft_nblen(y);
	res = (char *)malloc((x + neg) * sizeof(char));
	if (neg)
	{
		res[0] = '-';
		y = -y;
	}
	if (!y)
		return ("0");
	while (y)
	{
		res[x + neg] = (y % 10) + '0';
		x--;
		y /= 10;
	}
	return (res);
}
