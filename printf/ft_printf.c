/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:56:39 by rshay             #+#    #+#             */
/*   Updated: 2022/11/10 13:10:15 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char * s, ...)
{
	char	type;
	int	i;
	va_list	p;
	
	va_start(p, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			switch (s[i + 1])
			{
				case 'd' :
					ft_putnbr_fd(va_arg(p, int), 1);break;
				case 's' :
					ft_putstr_fd(va_arg(p, char *), 1);break;
				default :
					ft_putchar_fd(va_arg(p, int), 1);break;
			}
			i++;
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(p);
	return (0);
}

int	main ()
{
	ft_printf("je m'appelle %s%c, j'ai %d ans et je suis ne en %d\n","Rone", 'n', 19, 2003);
}
