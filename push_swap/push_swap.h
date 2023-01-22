/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:59 by lebronen          #+#    #+#             */
/*   Updated: 2023/01/20 21:18:50 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_swap
{
    int *t;
}       t_swap;

int bien_forme(char ** a, int x, t_swap *stack);
int in_tab(int *t, int x);
int is_nbr(char *s);


#endif