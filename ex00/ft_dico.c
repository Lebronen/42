/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dico.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:25:22 by rshay             #+#    #+#             */
/*   Updated: 2022/07/23 20:07:57 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_larousse.h"
#include <stdlib.h>
#include "ftr.h"

void	dict_desalloc(t_larousse *dict)
{
	t_larousse	*ptr;

	ptr = dict;
	while (ptr != NULL)
	{
		free(ptr);
		ptr = ptr->next;
	}
}

char	*get_item(t_larousse *dict, char *key)
{
	t_larousse	*ptr;

	ptr = dict;
	while (ptr != NULL)
	{
		if (!ft_strcmp(ptr->key, key))
			return (ptr->value);
	}
	return NULL;
}

t_larousse *dict_add_item(t_larousse *dict, char *key, char *value)
{
	t_larousse	*d;

	d = malloc(sizeof(struct s_larousse));
	d->key = malloc(ft_strlen(key)+1);
	ft_strcpy(d->key, key);
	d->value = malloc(ft_strlen(value)+1);
	ft_strcpy(d->value, value);
	d->next = dict;
	return d;
}

void	print_list(t_larousse *dict, int size)
{
	while (dict)
	{
		ft_putstr(dict->key);
		ft_putchar('\n');
		ft_putstr(dict->value);
		ft_putchar('\n');
		dict = dict->next;
	}
}

t_larousse	*ft_dico(char **keys, char **values, int size)
{
	t_larousse	*dict = 0;
	int		i;

	i = 0;
	while (i < size)
	{
		dict = dict_add_item(dict, keys[i], values[i]);
		i++;
	}
	return (dict);
}
