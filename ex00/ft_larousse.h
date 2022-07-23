/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_larousse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:50:01 by rshay             #+#    #+#             */
/*   Updated: 2022/07/23 16:51:25 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LAROUSSE_H
# define FT_LAROUSSE_H

typedef struct s_larousse
{
	char	*key;
	char	*value;
	struct s_larousse *next;
}		t_larousse;

#endif
