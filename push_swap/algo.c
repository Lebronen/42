/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:04:58 by rshay             #+#    #+#             */
/*   Updated: 2023/04/09 20:27:33 by lebronen         ###   ########.fr       */
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
	if (stack->len_a <= 5)
		small_sort(stack);
	else
		sort(stack);
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
	sens = -1;
	while (i < stack->len_a && stack->a[i] < x)
	{
		i++;
	}
	if (!i)
	{
		push_a(stack);
		return ;
	}
	if (stack->len_a - i < i)
	{
		sens = 1;
		j = stack->len_a;
	}
	set_up(stack, i, j, sens);
}

void	sort(t_swap *stack)
{
	int	i;
	int	j;
	int	x;
	int	sens;

	while (stack->len_a)
	{
		i = min_ind(stack, 0);
		j = min_ind(stack, 1);
		i = min(i - 1, stack->len_a - i + 1);
		x = min(j - 1, stack->len_a - j + 1);
		sens = 0;
		if (x < i)
			sens = 1;
		if (sens)
		{
			move_up(stack, j);
			push_b(stack);
		}
		ft_iter(stack, sens);
	}
	while (stack->len_b)
	{
		push_a(stack);
	}
}
