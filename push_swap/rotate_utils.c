/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:43:10 by rshay             #+#    #+#             */
/*   Updated: 2023/02/03 18:00:43 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(t_swap *stack)
{
    int i;
    int tmp1;
    int tmp2;

    if (stack->len_a <= 1)
        return ;
    i = 0;
    tmp1 = stack->a[0];
    tmp2 = stack->a[1];
    while (i < stack->len_a - 1)
    {
        tmp2 = stack->a[i + 1];
        stack->a[i + 1] = tmp1;
        tmp1 = tmp2;
        i++;
    }
    stack->a[0] = tmp1;
}

void    rotate_b(t_swap *stack)
{
    int i;
    int tmp1;
    int tmp2;

    if (stack->len_b <= 1)
        return ;
    i = 0;
    tmp1 = stack->b[0];
    tmp2 = stack->b[1];
    while (i < stack->len_b - 1)
    {
        tmp2 = stack->b[i + 1];
        stack->b[i + 1] = tmp1;
        tmp1 = tmp2;
        i++;
    }
    stack->b[0] = tmp1;
}