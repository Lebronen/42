/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:10:15 by rshay             #+#    #+#             */
/*   Updated: 2023/02/20 17:42:35 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	bin(int x)
{
	if (x < 2)
		return x % 2;
	return (x % 2 + 10 * bin(x / 2));
}

int	*tribulle(t_swap stack)
{
	int	i;
	int	j;
	int	tmp;
	int	*t;

	t = malloc(sizeof(int) * stack.len_a);
	ft_memcpy(t, stack.a, stack.len_a * sizeof(int));
	i = stack.len_a - 1;
	while (i)
	{
		j = 0;
		while (j < i)
		{
			if (t[j] > t[j + 1])
			{
				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
		j++;
		}
	i--;
	}
	return (t);
}

int	ft_index(int *t, int x)
{
	int	i;

	i =0;
	while (t[i])
	{
		if (t[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

void	simplify(t_swap *stack)
{
	int	i;
	int	*sorted;
	int	*t;

	t = malloc(stack->len_a * sizeof(int));
	i = 0;
	sorted = tribulle(*stack);
	while (i < stack->len_a)
	{
		t[i] = bin(ft_index(sorted, stack->a[i]));
		i++;
	}
	stack->a = t;
}
