/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:56:11 by rshay             #+#    #+#             */
/*   Updated: 2023/02/06 17:40:20 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr(size_t n, char *base)
{
	size_t	y;

	y = ft_strlen(base);
	if (n >= y)
	{
		ft_putaddr(n / y, base);
		ft_putchar_fd(base[n % y], 1);
	}
	else
		ft_putchar_fd(base[n], 1);
}
