/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:59 by lebronen          #+#    #+#             */
/*   Updated: 2023/04/09 22:35:48 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_swap
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}		t_swap;

int		bien_forme(char **a, int x, t_swap *stack);
int		in_tab(int *t, int x);
int		is_nbr(char *s);
int		ft_len(char **s);
void	free_tab(char **s);
void	aff_tab(int *t, int size);
void	swap_a(t_swap *stack);
void	swap_b(t_swap *stack);
void	swap_ab(t_swap *stack);
void	push_a(t_swap *stack);
void	push_b(t_swap *stack);
void	rotate_a(t_swap *stack);
void	rotate_b(t_swap *stack);
void	reverse_rotate_a(t_swap *stack);
void	reverse_rotate_b(t_swap *stack);
void	rotate_ab(t_swap *stack);
void	reverse_ab(t_swap *stack);
int		verif(t_swap stack);
void	algo(t_swap *stack);
int		is_sort(t_swap stack);
int		*tribulle(int *t, int len);
void	simplify(t_swap *stack);
int		ft_index(int *t, int x);
void	small_sort(t_swap *stack);
void	insert(t_swap *stack);
int		bin(int x);
void	case_three(t_swap *stack);
int		min_ind(t_swap *stack, int x);
int 	max_element(t_swap *stack, int x);
int 	max_tab(t_swap *stack);
void	move_up(t_swap *stack, int i);
int 	max(int x, int y);
int		min(int x, int y);
void	sort(t_swap *stack);
void	ft_iter(t_swap *stack, int sens);
int		loop_min(t_swap *stack, int min_1, int min_2, int x);
void	set_up(t_swap *stack, int i, int j, int sens);
void	push_loop_a(t_swap *stack);
void	push_loop_b(t_swap *stack);
int		distance(t_swap *stack, int deb, int fin);
void	big_sort(t_swap *stack);
int		from_chunk(t_swap *stack, int *chunk);
void    set_loop(t_swap *stack, int x);
void 	place_b(t_swap *stack, int x);
void    order_b(t_swap *stack);

#endif
