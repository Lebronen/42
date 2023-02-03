/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:59 by lebronen          #+#    #+#             */
/*   Updated: 2023/02/03 17:49:04 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_swap
{
    int *a;
    int *b;
    int len_a;
    int len_b;
}       t_swap;

int     bien_forme(char ** a, int x, t_swap *stack);
int     in_tab(int *t, int x);
int     is_nbr(char *s);
void    aff_tab(int *t);
void    swap_a(t_swap *stack);
void    swap_b(t_swap *stack);
void    swap_ab(t_swap *stack);
void    push_a(t_swap *stack);
void    push_b(t_swap *stack);
void    rotate_a(t_swap *stack);

#endif