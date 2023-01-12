/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:15:58 by lebronen          #+#    #+#             */
/*   Updated: 2023/01/12 00:32:03 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	str_comp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

double	ft_atoi(char *s)
{
	double	nb;
	int		i;
	int		neg;

	neg = 1;
	nb = 0;
	i = 0;
	if (s[0] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] && s[i] != '.')
	{
		nb *= 10;
		nb += s[i] - 48;
		i++;
		printf("%f\n", nb);
	}
	if (!s[i])
		return (neg * nb);
	else
	{
		return (atoi_dec(nb, neg, s + i));
	}
}

double	atoi_dec(double nb, int neg, char *s)
{
	int		i;
	double	dec;

	i = 1;
	dec = 0;
	while (s[i])
	{
		dec += pow_ten(s[i] - 48, i);
		i++;
	}
	return (neg * (dec + nb));
}

double	pow_ten(double x, int i)
{
	while (i)
	{
		x /= 10;
		i--;
	}
	return (x);
}
