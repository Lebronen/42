/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:57:13 by rshay             #+#    #+#             */
/*   Updated: 2022/09/03 16:05:48 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	x;

	x = n;
	if (x < 0)
	{
		x = -x;
		ft_putchar_fd('-', fd);
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putchar_fd((x % 10) + '0', fd);
	}
	else
		ft_putchar_fd(x + '0', fd);
}
