/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:13:14 by lebronen          #+#    #+#             */
/*   Updated: 2023/03/05 19:26:35 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	case_three(t_swap *stack)
{
	if (is_sort(*stack))
		return ;
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
