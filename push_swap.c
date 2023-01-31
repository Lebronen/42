/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:25:06 by lebronen          #+#    #+#             */
/*   Updated: 2023/01/22 17:14:57 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
    t_swap  stack;
    
    if (argc <= 1 || !bien_forme(argv, argc, &stack))
    {
        ft_printf("Error");
        return (0);
    }
    
}

int bien_forme(char ** a, int x, t_swap *stack)
{
    int i;

    i = 1;
    stack->t = malloc(sizeof(int) * x);
    while (i < x)
    {
        if (!is_nbr(a[i]))
            return (0);
        if (in_tab(stack->t, ft_atoi(a[i])))
            return (0);
        (stack->t)[i] = ft_atoi(a[i]);
        i++;
    }
    return (1);
}

int in_tab(int *t, int x)
{
    int i;

    i = 0;
    while (t[i])
    {
        if (t[i] == x)
            return (1);
        i++;
    }
    return (0);
}

int is_nbr(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] < 48 || s[i] > 57)
            return (0);
        i++;
    }
    return (1);
}