/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:26:32 by rshay             #+#    #+#             */
/*   Updated: 2022/10/09 18:11:08 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nc;

	nc = malloc(sizeof(t_list));
	if (!nc)
		return (NULL);
	nc->content = content;
	nc->next = NULL;
	return (nc);
}
