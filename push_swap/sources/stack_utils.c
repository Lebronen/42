/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:43:13 by lebronen          #+#    #+#             */
/*   Updated: 2023/04/23 18:43:14 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	new_stack(char name, bool silent)
{
	t_stack	stack;

	stack.name = name;
	stack.head = NULL;
	stack.size = 0;
	stack.silent = silent;
	return (stack);
}

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->data = data;
	new->next = NULL;
	return (new);
}

void	cicrular_doubly_list_addback(t_node **list, t_node *new)
{
	if (!list)
		return ;
	if (*list)
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		*list = new;
	}
}

void	cicrular_doubly_list_addfront(t_node **list, t_node *new)
{
	if (!list)
		return ;
	if (*list)
	{
		(*list)->prev->next = new;
		new->next = (*list);
		new->prev = (*list)->prev;
		(*list)->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
	}
	*list = new;
}

void	clear_nodes(t_stack *stack)
{
	t_node	*tmp;
	t_node	*list;
	t_node	*first;

	if (!stack->head)
		return ;
	first = stack->head;
	list = first->next;
	while (list && list != first)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(first);
	stack->head = NULL;
}
