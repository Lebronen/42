/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:49:46 by rshay             #+#    #+#             */
/*   Updated: 2022/10/09 18:20:53 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*begin;

	if (!lst || !f)
		return NULL;
	t = malloc (ft_lstsize(lst) * sizeof(*lst));
	begin = t;
	if (!t)
		return NULL;
	while (lst)
	{
		t->content = f(lst->content);
		t->next = ++t;
		lst = lst->next;
	}
	return begin;
}


int	main()
{
	int x = 5;
	int y = 4;
	t_list	*t = ft_lstnew(x);
	ft_lstadd_front(&t, ft_lstnew(4));
	printf("%ld", ( long int)t->next->content);
	return (0);
}
