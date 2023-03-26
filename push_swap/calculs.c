/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:03:45 by lebronen          #+#    #+#             */
/*   Updated: 2023/03/26 20:11:28 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	distance(t_swap *stack, int deb, int fin)
{
	int	i;
	int	j;
	int	*t;

	i = 0;
	j = stack->len_a - 1;
	t = stack->a;
	while (t[i] < deb || t[i] > fin)
	{
		i++;
	}
	while (t[j] < deb || t[j] > fin)
	{
		j--;
	}
	return (min(i, stack->len_a - j));
}