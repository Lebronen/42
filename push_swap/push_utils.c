/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:44:53 by rshay             #+#    #+#             */
/*   Updated: 2023/02/21 16:39:08 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	push_a(t_swap *stack)
{
	int	temp;
	int	*nb;
	int	*na;

	ft_printf("pa\n");
	if (!stack->len_b)
		return ;
	temp = (stack->b)[0];
	stack->len_b -= 1;
	stack->len_a += 1;
	na = ft_calloc(stack->len_a + 1 ,sizeof(int));
	nb = ft_calloc(stack->len_b + 1 ,sizeof(int));
	if (stack->len_b)
		ft_memcpy(nb, stack->b + 1, (stack->len_b) * sizeof(int));
	na[0] = temp;
	ft_memcpy(na + 1, stack->a, (stack->len_a) * sizeof(int));
	free(stack->a);
	free(stack->b);
	stack->a = na;
	stack->b = nb;
	//stack->a = ft_calloc(stack->len_a, sizeof(int));
	//stack->b = ft_calloc(stack->len_b, sizeof(int));
	//ft_memcpy(stack->a, na, stack->len_a * sizeof(int));
	//ft_memcpy(stack->b, nb, stack->len_b * sizeof(int));
	//free(na);
	//free(nb);
}

void	push_b(t_swap *stack)
{
	int	temp;
	int	*nb;
	int	*na;

	ft_printf("pb\n");
	if (!stack->len_a)
		return ;
	temp = (stack->a)[0];
	stack->len_a -= 1;
	stack->len_b += 1;
	na = ft_calloc(stack->len_a + 1, sizeof(int));
	nb = ft_calloc(stack->len_b + 1, sizeof(int));
	if (stack->len_a)
		ft_memcpy(na, stack->a + 1, (stack->len_a) * sizeof(int));
	nb[0] = temp;
	ft_memcpy(nb + 1, stack->b, (stack->len_b) * sizeof(int));
	free(stack->a);
	free(stack->b);
	stack->a = na;
	stack->b = nb;
	//ft_memcpy(nb + 1, stack->b, (stack->len_b) * sizeof(int));
	//stack->a = ft_calloc(stack->len_a, sizeof(int));
	//stack->b = ft_calloc(stack->len_b, sizeof(int));
	//ft_memcpy(stack->a, na, stack->len_a * sizeof(int));
	//ft_memcpy(stack->b, nb, stack->len_b * sizeof(int));
}
