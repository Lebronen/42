/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:43:10 by rshay             #+#    #+#             */
/*   Updated: 2023/02/13 17:52:04 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	reverse_rotate_a(t_swap *stack)
{
	int	i;
	int	tmp1;
	int	tmp2;

	ft_printf("rra\n");
	if (stack->len_a <= 1)
		return ;
	i = 0;
	tmp1 = stack->a[0];
	while (i < stack->len_a - 1)
	{
		tmp2 = stack->a[i + 1];
		stack->a[i + 1] = tmp1;
		tmp1 = tmp2;
		i++;
	}
	stack->a[0] = tmp1;
}

void	reverse_rotate_b(t_swap *stack)
{
	int	i;
	int	tmp1;
	int	tmp2;

	ft_printf("rrb\n");
	if (stack->len_b <= 1)
		return ;
	i = 0;
	tmp1 = stack->b[0];
	while (i < stack->len_b - 1)
	{
		tmp2 = stack->b[i + 1];
		stack->b[i + 1] = tmp1;
		tmp1 = tmp2;
		i++;
	}
	stack->b[0] = tmp1;
}

void	rotate_a(t_swap *stack)
{
	int	i;
	int	tmp1;
	int	tmp2;

	ft_printf("ra\n");
	if (stack->len_a <= 1)
		return ;
	i = stack->len_a - 1;
	tmp1 = stack->a[i];
	while (i >= 1)
	{
		tmp2 = stack->a[i - 1];
		stack->a[i - 1] = tmp1;
		tmp1 = tmp2;
		i--;
	}
	stack->a[stack->len_a - 1] = tmp1;
}

void	rotate_b(t_swap *stack)
{
	int	i;
	int	tmp1;
	int	tmp2;

	ft_printf("rb\n");
	if (stack->len_b <= 1)
		return ;
	i = stack->len_b - 1;
	tmp1 = stack->b[i];
	while (i >= 1)
	{
		tmp2 = stack->b[i - 1];
		stack->b[i - 1] = tmp1;
		tmp1 = tmp2;
		i--;
	}
	stack->b[stack->len_b - 1] = tmp1;
}
