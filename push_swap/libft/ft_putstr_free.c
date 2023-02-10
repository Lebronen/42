/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:06:31 by rshay             #+#    #+#             */
/*   Updated: 2023/02/06 17:41:16 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_free(const char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	free((void *)s);
	return (i);
}
