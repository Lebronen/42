/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:10:15 by rshay             #+#    #+#             */
/*   Updated: 2023/03/27 17:24:31 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	min_ind(t_swap *stack, int x)
{
	int	min_1;
	int	min_2;

	if (!stack->len_a)
		return (-1);
	if (stack->len_a == 1)
		return (0);
	min_1 = 0;
	min_2 = 1;
	if (stack->a[0] > stack->a[1])
	{
		min_1 = 1;
		min_2 = 0;
	}
	return (loop_min(stack, min_1, min_2, x));
}

int	loop_min(t_swap *stack, int min_1, int min_2, int x)
{
	int	i;

	i = 1;
	while (i < stack->len_a)
	{
		if (stack->a[i] < stack->a[min_2])
		{
			if (stack->a[i] < stack->a[min_1])
				min_1 = i;
			else
				min_2 = i;
		}
		i++;
	}
	if (x)
		return (min_2);
	return (min_1);
}

void	move_up(t_swap *stack, int i)
{
	int	x;
	int	sens;

	ft_printf("i = %d\n", i);
	if (stack->len_a - i < i)
		sens = 1;
	else
		sens = 0;
	x = stack->a[i];
	while (stack->a[0] != x)
	{
		if (sens)
			reverse_rotate_a(stack);
		else
		{
			rotate_a(stack);
		}
	}
}

void	ft_iter(t_swap *stack, int sens)
{
	move_up(stack, min_ind(stack, 1));
	push_b(stack);
	if (sens)
		swap_b(stack);
}

void	set_up(t_swap *stack, int i, int j, int sens)
{
	while (j != i)
	{
		if (sens == 1)
			reverse_rotate_a(stack);
		else
			rotate_a(stack);
		j -= sens;
	}
	if (sens == 1)
	{
		push_loop_a(stack);
		while (j++ < stack->len_a)
		{
			rotate_a(stack);
		}
	}
	else
	{
		push_loop_b(stack);
		while (j--)
		{
			reverse_rotate_a(stack);
		}
	}
}
