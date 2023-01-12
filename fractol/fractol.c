/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:22:09 by lebronen          #+#    #+#             */
/*   Updated: 2023/01/12 18:42:31 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx.h"
#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>

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

	if (argc == 1)
	{
		return (0);
	}
	init(&vars, &img);
	if (str_comp(argv[1], "mandelbrot"))
	{
		if (argc != 2)
			return (0);
		vars.d = 'm';
	}
	else if (str_comp(argv[1], "julia"))
	{
		if (argc != 4)
			return (0);
		vars.px = ft_atoi(argv[2]);
		vars.py = ft_atoi(argv[3]);
		vars.d = 'j';
	}
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
			i = fractale(c, z, vars.max);
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

int	fractale(t_comp c, t_comp z, int max)
{
	int		i;

	i = 0;
	while (i < max && norme_comp(z) < 4)
	{
		z = add_comp(prod_comp(z, z), c);
		i++;
	}
	return (i);
}
