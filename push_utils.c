/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:44:53 by rshay             #+#    #+#             */
/*   Updated: 2023/01/23 16:40:50 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_swap *stack)
{
    int temp;
    int *nb;
    int *na;

    if (!stack->len_b)
        return (0);
    temp = (stack->b)[0];
    stack->len_b -= 1;
    stack->len_a += 1;
    nb = malloc(sizeof(int) * stack->len_b);
    na = malloc(sizeof(int) * stack->len_a);
    ft_strlcpy(nb, stack->b + 1, len_b);
    na[0] = temp;
    ft_strlcat(na, stack->a, stack->len_a);
    free(stack->a);
    free(stack->b);
    stack->a = na;
    stack->b = nb;
}

void    push_b(t_swap *stack)
{
    int temp;
    int *nb;
    int *na;

    if (!stack->len_a)
        return (0);
    temp = (stack->a)[0];
    stack->len_a -= 1;
    stack->len_b += 1;
    na = malloc(sizeof(int) * stack->len_a);
    nb = malloc(sizeof(int) * stack->len_b);
    ft_strlcpy(nb, stack->a + 1, len_a);
    na[0] = temp;
    ft_strlcat(nb, stack->b);
    stack->b = nb;
    stack->a = na;
}