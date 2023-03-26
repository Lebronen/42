/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:19:07 by lebronen          #+#    #+#             */
/*   Updated: 2023/03/26 21:34:38 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	big_sort(t_swap *stack)
{
    (void)stack;
	//int *t;

    //t = tribulle(stack->a, stack->len_a);
}    

int *tribulle(int *tab, int len)
{
    int i;
    int j;
    int c;
    int *t;
    
    t = malloc(len * sizeof(int));
    ft_memmove(t, tab, len * sizeof(int));
    i = 0;
    while (i < len - 1)
    {
        j = 0;
        while (j < len - i - 1)
        {
            if (t[j] > t[j+1])
            {
                c = t[j];
                t[j] = t[j+1];
                t[j+1] = c;
            }
            j++;
        }
        i++;
    }
    return (t);
}