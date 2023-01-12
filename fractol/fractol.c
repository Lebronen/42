/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:22:09 by lebronen          #+#    #+#             */
/*   Updated: 2023/01/12 01:05:28 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_data		img;

	if (argc == 1)
	{
		return (0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W, H, "window");
	img.img = mlx_new_image(vars.mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	vars.img = &img;
	vars.color = 0;
	vars.zoom = 0.5;
	vars.move_x = 0;
	vars.move_y = 0;
	if (str_comp(argv[1], "mandelbrot"))
	{
		vars.d = 'm';
	}
	else if (str_comp(argv[1], "julia"))
	{
		vars.px = ft_atoi(argv[2]);
		vars.py = ft_atoi(argv[3]);
		vars.d = 'j';
		printf ("%f %f\n", vars.px, vars.py);
	}
	put_fractale(&img, 45, vars);
	mlx_hook(vars.win, 17, 1L << 0, close, &vars);
	mlx_hook(vars.win, 2, 1L << 0, clavier, &vars);
	mlx_mouse_hook(vars.win, dive, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	return (0);
}

void	put_fractale(t_data *img, int max, t_vars vars)
{
	int		x;
	int		y;
	t_comp	c;
	int		i;
	t_comp	z;

	x = 0;
	c.r = vars.px;
	c.i = vars.py;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			if (vars.d == 'm')
			{
				c = coord_to_comp(x, y, vars);
				z.r = 0;
				z.i = 0;
			}
			else
			{
				z = coord_to_comp(x, y, vars);
			}
			i = fractale(c, z, max);
			if (i != max)
				my_mlx_pixel_put(img, x, y, (i * 0xAB42EFFF) % 0xFFFFFFFF);
			else
				my_mlx_pixel_put(img, x, y, 0x00000000);
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
