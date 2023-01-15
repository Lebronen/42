/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:22:09 by lebronen          #+#    #+#             */
/*   Updated: 2023/01/15 22:09:59 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;
	int		i;

	if (argc == 1)
	{
		ft_putstr("veuillez entrer au moins un paramètre");
		return (0);
	}
	init(&vars, &img);
	i = verif_params(argc, argv, &vars);
	if (i)
		return (0);
	loop(&vars, &img);
	return (0);
}

void	put_fractale(t_vars vars, t_comp c, int x, int y)
{
	int		i;
	t_comp	z;
	t_coord	p;

	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			p.x = x;
			p.y = y;
			set_c_and_z(&c, &z, vars, p);
			i = fractale(c, z, vars.max, vars);
			if (i != vars.max)
				my_mlx_pixel_put(vars.img, x, y, (i * 0xAB42EFFF) % 0xFFFFFFFF);
			else
				my_mlx_pixel_put(vars.img, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}

t_comp	coord_to_comp(int x, int y, t_vars vars)
{
	t_comp	pixel;

	pixel.r = (x - W / 2) / (0.5 * vars.zoom * W) + vars.move_x;
	pixel.i = (y - H / 2) / (0.5 * vars.zoom * H) + vars.move_y;
	return (pixel);
}

int	fractale(t_comp c, t_comp z, int max, t_vars vars)
{
	int		i;

	i = 0;
	while (i < max && norme_comp(z) < 4)
	{
		if (vars.d == 'b')
		{
			z.r = absolue(z.r);
			z.i = absolue(z.i);
		}
		z = add_comp(prod_comp(z, z), c);
		i++;
	}
	return (i);
}
