/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:00:56 by rshay             #+#    #+#             */
/*   Updated: 2023/01/31 11:01:09 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void    swap_a(t_swap *stack)
{
    int temp;
    
    if (stack->len_a <= 1)
        return ;
    temp = (stack->a)[0];
    ft_printf("temp = %d\n", temp);
    (stack->a)[0] = (stack->a)[1];
    ft_printf("temp = %d\n", temp);
    (stack->a)[1] = temp;
}

void    swap_b(t_swap *stack)
{
    int temp;
    
    if (stack->len_b <= 1)
        return ;
    temp = (stack->b)[0];
    (stack->b)[0] = (stack->b)[1];
    (stack->b)[1] = temp;
}

void    swap_ab(t_swap *stack)
{
    swap_a(stack);
    swap_b(stack);
}