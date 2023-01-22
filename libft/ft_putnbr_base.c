/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:56:00 by rshay             #+#    #+#             */
/*   Updated: 2023/01/20 20:57:14 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned int n, char *base)
{
	long long int	x;
	long long int	y;

	x = n;
	y = ft_strlen(base);
	if (x >= y)
	{
		ft_putnbr_base(x / y, base);
		ft_putchar_fd(base[x % y], 1);
	}
	else
		ft_putchar_fd(base[x], 1);
}
