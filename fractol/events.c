/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:12:12 by rshay             #+#    #+#             */
/*   Updated: 2023/01/20 09:14:38 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	close(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	clavier(int keycode, t_vars *vars)
{
	t_comp	c;

	if (keycode == 65307)
	{
		mlx_loop_end(vars->mlx);
	}
	else if (keycode == 65361)
		vars->move_x += 0.1;
	else if (keycode == 65362)
		vars->move_y += 0.1;
	else if (keycode == 65363)
		vars->move_x -= 0.1;
	else if (keycode == 65364)
		vars->move_y -= 0.1;
	c.r = vars->px;
	c.i = vars->py;
	put_fractale(*vars, c, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	dive(int button, int x, int y, t_vars *vars)
{
	t_comp	c;

	if (button == 4 || button == 5)
	{
		if (button == 4)
			vars->zoom *= 1.1;
		else if (button == 5 && vars->zoom > 0.02)
			vars->zoom /= 1.1;
		vars->move_x = (x - W / 2) / (3 * vars->zoom * W) + vars->move_x;
		vars->move_y = (y - H / 2) / (3 * vars->zoom * H) + vars->move_y;
		(void)x;
		(void)y;
	}
	else if (button == 1)
		vars->c += 0x72618414;
	else if (button == 3)
		vars->c /= 16;
	c.r = vars->px;
	c.i = vars->py;
	put_fractale(*vars, c, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}
