/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:14:30 by rshay             #+#    #+#             */
/*   Updated: 2022/11/09 16:21:35 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_ws(char c)
{
	return (c <= 13 || c == ' ');
}

int	ft_atoi(const char *str)
{
	int				i;
	int				is_neg;
	int				res;

	i = 0;
	while (is_ws(str[i]) && str[i])
		i++;
	if (str[i] == '-')
		is_neg = -1;
	else
		is_neg = 1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_neg);
}
