/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:29:23 by rshay             #+#    #+#             */
/*   Updated: 2023/01/12 18:45:13 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "include/mlx.h"

void	init(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, W, H, "window");
	img->img = mlx_new_image(vars->mlx, W, H);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l, &img->endian);
	vars->img = img;
	vars->color = 0;
	vars->zoom = 0.5;
	vars->move_x = 0;
	vars->move_y = 0;
	vars->max = 45;
}

void	loop(t_vars *vars, t_data *img)
{
	t_comp	c;

	c.r = vars->px;
	c.i = vars->py;
	put_fractale(*vars, c, 0, 0);
	mlx_hook(vars->win, 17, 1L << 0, close, vars);
	mlx_hook(vars->win, 2, 1L << 0, clavier, vars);
	mlx_mouse_hook(vars->win, dive, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_loop(vars->mlx);
	free(vars->mlx);
}

void	set_c_and_z(t_comp *c, t_comp *z, t_vars vars, t_coord p)
{
	if (vars.d == 'm')
	{
		*c = coord_to_comp(p.x, p.y, vars);
		z->r = 0;
		z->i = 0;
	}
	else
	{
		*z = coord_to_comp(p.x, p.y, vars);
	}
}
