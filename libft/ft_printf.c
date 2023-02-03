/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:56:39 by rshay             #+#    #+#             */
/*   Updated: 2022/11/15 16:50:57 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_pointeur(void *p)
{
	char	*s;

	s = "0123456789abcdef";
	if (!p)
		return (ft_putstr_len("(nil)"));
	ft_putstr_fd("0x", 1);
	return (2 + ft_putstr_free((const char *)ft_sizetoa((size_t)p, s)));
}

static int	ft_put_hex(unsigned int n, char c)
{
	if (ft_is_lower(c))
		return (ft_putstr_free(ft_ustoa(n, "0123456789abcdef")));
	else
		return (ft_putstr_free(ft_ustoa(n, "0123456789ABCDEF")));
}

static int	ft_affiche(char f, va_list p)
{
	if (f == 'd' || f == 'i')
		return (ft_putstr_free(ft_itoa(va_arg(p, int))));
	else if (f == 's')
		return (ft_putstr_len(va_arg(p, char *)));
	else if (f == 'c')
	{
		ft_putchar_fd(va_arg(p, int), 1);
		return (1);
	}
	else if (f == '%')
	{
		return (ft_putchar_fd('%', 1));
	}
	else if (f == 'u')
		return (ft_putstr_free(ft_itoa_ns(va_arg(p, unsigned int))));
	else if (f == 'x' || f == 'X')
		return (ft_put_hex(va_arg(p, unsigned int), f));
	else if (f == 'p')
		return (ft_pointeur(va_arg(p, void *)));
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(f, 1);
		return (1);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	p;
	int		x;

	x = 0;
	va_start(p, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			x += ft_affiche(s[i + 1], p);
			i++;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			x++;
		}
		i++;
	}
	va_end(p);
	return (x);
}
