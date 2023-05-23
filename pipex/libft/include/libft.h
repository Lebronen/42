/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:29:35 by rshay             #+#    #+#             */
/*   Updated: 2023/05/22 17:30:04 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *str, const char *sub, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);

#endif
