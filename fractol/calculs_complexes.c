/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_complexes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:50:41 by lebronen          #+#    #+#             */
/*   Updated: 2023/01/12 00:24:49 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

t_comp	add_comp(t_comp a, t_comp b)
{
	t_comp	res;

	res.r = a.r + b.r;
	res.i = a.i + b.i;
	return (res);
}

t_comp	prod_comp(t_comp a, t_comp b)
{
	t_comp	res;

	res.r = (a.r * b.r) - (a.i * b.i);
	res.i = (a.r * b.i) + (a.i * b.r);
	return (res);
}

int	norme_comp(t_comp z)
{
	return (z.r * z.r + z.i * z.i);
}
