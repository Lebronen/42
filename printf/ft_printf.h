/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:51:31 by rshay             #+#    #+#             */
/*   Updated: 2022/11/16 11:07:02 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *s, ...);

char		*ft_itoa(int n);

void		ft_putaddr(size_t n, char *base);

int			ft_putchar_fd(char c, int fd);

void		ft_putnbr_base(unsigned int n, char *base);

void		ft_putstr_fd(char *s, int fd);

int			ft_putstr_len(char *s);

int			ft_is_lower(char c);

int			ft_strlen(const char *s);

int			ft_putstr_free(const char *s);

char		*ft_itoa_ns(unsigned int n);

char		*ft_sizetoa(size_t n, char *base);

char		*ft_ustoa(unsigned int n, char *base);

#endif
