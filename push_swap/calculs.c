/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:03:45 by lebronen          #+#    #+#             */
/*   Updated: 2023/04/09 22:35:12 by lebronen         ###   ########.fr       */
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

int	ft_len(char **s)
{
	int	i;

	i = 0;
	while (*s++)
	{
		i++;
	}
	return (i);
}

void	free_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}