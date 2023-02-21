/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:04:58 by rshay             #+#    #+#             */
/*   Updated: 2023/02/21 14:24:00 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	algo(t_swap *stack)
{
	if (is_sort(*stack))
		return ;
	if (stack->len_a < 3)
	{
		ft_printf("sa");
		return ;
	}
	small_sort(stack);
}

int	is_sort(t_swap stack)
{
	int	i;

	i = 0;
	while (i < stack.len_a - 1)
	{
		if (stack.a[i] > stack.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	small_sort(t_swap *stack)
{
	if (stack->len_a == 3)
	{
		case_three(stack);
		while (stack->len_b)
		{
			insert(stack);
		}
	}
	else
	{
		push_b(stack);
		small_sort(stack);
	}
}

void	insert(t_swap *stack)
{
	int	x;
	int	i;
	int	j;
	int	sens;

	x = stack->b[0];
	i = 0;
	j = 0;
	sens = 0;
	while (i < stack->len_a && stack->a[i] < x)
	{
		i++;
	}
	if (stack->len_a - i < i)
	{
		sens = 1;
		j = stack->len_a;
	}
	while (j != i)
	{
		if (sens)
		{
			reverse_rotate_a(stack);
			j--;
		}
		else
		{
			rotate_a(stack);
			j++;
		}
	}
	push_a(stack);
	if (sens)
	{
		while (j < stack->len_a)
		{
			rotate_a(stack);
			j++;
		}
	}
	else
	{
		while (j)
		{
			reverse_rotate_a(stack);
			j--;
		}
	}
}

void	case_three(t_swap *stack)
{
	if (stack->a[0] > stack->a[1])
	{
		if (stack->a[1] > stack->a[2])
		{
				rotate_a(stack);
				swap_a(stack);
		}
		else if (stack->a[0] > stack->a[2])
			rotate_a(stack);
		else
			swap_a(stack);
	}
	else
	{
		if (stack->a[0] < stack->a[2])
		{
			reverse_rotate_a(stack);
			swap_a(stack);
		}
		else
			reverse_rotate_a(stack);
	}
}
