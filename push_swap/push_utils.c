/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:44:53 by rshay             #+#    #+#             */
/*   Updated: 2023/01/31 11:15:02 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void    push_a(t_swap *stack)
{
    int temp;
    int *nb;
    int *na;

    if (!stack->len_b)
        return;
    temp = (stack->b)[0];
    stack->len_b -= 1;
    stack->len_a += 1;
    nb = malloc(sizeof(int) * stack->len_b);
    na = malloc(sizeof(int) * stack->len_a);
    ft_strlcpy((char *)nb, (char *)stack->b + 1, stack->len_b);
    na[0] = temp;
    ft_strlcat((char *)na, (char *)stack->a, stack->len_a);
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
        return;
    temp = (stack->a)[0];
    stack->len_a -= 1;
    stack->len_b += 1;
    na = malloc(sizeof(int) * stack->len_a);
    nb = malloc(sizeof(int) * stack->len_b);
    ft_strlcpy((char *)nb, (char *)stack->a + 1, stack->len_a);
    na[0] = temp;
    ft_strlcat((char *)nb, (char *)stack->b, stack->len_b);
    stack->b = nb;
    stack->a = na;
}