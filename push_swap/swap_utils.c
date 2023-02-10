/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:18:12 by lebronen          #+#    #+#             */
/*   Updated: 2023/02/10 17:27:08 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap_a(t_swap *stack)
{
	int	temp;

	if (stack->len_a <= 1)
		return ;
	temp = (stack->a)[0];
	(stack->a)[0] = (stack->a)[1];
	(stack->a)[1] = temp;
}

void	swap_b(t_swap *stack)
{
	int	temp;

	if (stack->len_b <= 1)
		return ;
	temp = (stack->b)[0];
	(stack->b)[0] = (stack->b)[1];
	(stack->b)[1] = temp;
}

void	swap_ab(t_swap *stack)
{
	swap_a(stack);
	swap_b(stack);
}
