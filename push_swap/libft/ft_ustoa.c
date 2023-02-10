/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:12:59 by rshay             #+#    #+#             */
/*   Updated: 2023/02/06 17:41:31 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned int n, char *base)
{
	int	size;

	size = 1;
	n /= ft_strlen(base);
	while (n)
	{
		++size;
		n /= ft_strlen(base);
	}
	return (size);
}

static void	ft_itoa2(char *s, unsigned int n, int len, char *base)
{
	if (n)
	{
		s[len] = (base[n % ft_strlen(base)]);
		ft_itoa2(s, n / ft_strlen(base), len - 1, base);
	}
}

char	*ft_ustoa(unsigned int n, char *base)
{
	int		size;
	char	*result;

	size = get_size(n, base);
	result = (char *)malloc((size + 1) * sizeof (*result));
	if (result != NULL)
	{
		if (n == 0)
			result[0] = '0';
		ft_itoa2(result, n, size - 1, base);
		result[size] = '\0';
	}
	return (result);
}
