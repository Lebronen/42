/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:47:03 by lebronen          #+#    #+#             */
/*   Updated: 2023/04/23 18:47:04 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_head(t_push_swap *ps, t_stack *stack, t_node *element)
{
	void	(*r)(t_push_swap *ps, t_stack *);

	if (!stack || !element || stack->size < 2)
		return ;
	if (get_pos(stack, element) * 2 > stack->size)
		r = &rrotate;
	else
		r = &rotate;
	while (element != stack->head)
		r(ps, stack);
}

void	make_rotations(t_push_swap *ps, t_rotation *rotation)
{
	while (rotation->a_count || rotation->b_count)
	{
		if (rotation->a_count)
		{
			rotation->a_fun(ps, &ps->a);
			rotation->a_count--;
		}
		if (rotation->b_count)
		{
			rotation->b_fun(ps, &ps->b);
			rotation->b_count--;
		}
	}
}

void	sort_three(t_push_swap *ps, t_stack *s, bool (*cmp)(int, int))
{
	if (!s || is_sorted(s, 3, cmp))
		return ;
	if (s->head->data > s->head->next->data)
	{
		if (s->head->data < s->head->prev->data)
			return (swap(ps, s));
		rotate(ps, s);
		if (s->head->data > s->head->next->data)
			swap(ps, s);
		return ;
	}
	else if (s->head->data > s->head->prev->data)
		return (rrotate(ps, s));
	rrotate(ps, s);
	swap(ps, s);
}

static size_t	insert_index(t_stack *stack, int data)
{
	t_node	*tmp;
	t_node	*min;
	size_t	index;

	if (!stack || !stack->size)
		return (0);
	min = get_min(stack);
	if (data < min->data || data > min->prev->data)
		return (get_pos(stack, min));
	index = 0;
	tmp = stack->head;
	while (index < stack->size)
	{
		if (tmp->data > data && tmp->prev->data < data)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

/*
0: ra
1: rra
2: rb
3: rrb
*/
void	get_moves(t_push_swap *ps, t_node *node, size_t moves[4])
{
	moves[0] = insert_index(&ps->a, node->data);
	moves[1] = ps->a.size - moves[0];
	moves[2] = get_pos(&ps->b, node);
	moves[3] = ps->b.size - moves[2];
}
