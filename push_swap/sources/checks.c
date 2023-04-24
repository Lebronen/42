/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:46:08 by lebronen          #+#    #+#             */
/*   Updated: 2023/04/23 18:46:09 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	in_list(t_node *list, int data)
{
	t_node	*first;

	if (!list)
		return (false);
	if (list->data == data)
		return (true);
	first = list;
	list = first->next;
	while (list != first)
	{
		if (list->data == data)
			return (true);
		list = list->next;
	}
	return (false);
}

bool	is_sorted(t_stack *stack, size_t size, bool (*cmp)(int, int))
{
	t_node	*list;

	list = stack->head;
	if (!list)
		return (true);
	while (--size)
	{
		if (!cmp(list->data, list->next->data))
			return (false);
		list = list->next;
	}
	return (true);
}

bool	ascending(int src, int next)
{
	return (src <= next);
}

bool	descending(int src, int next)
{
	return (src >= next);
}
