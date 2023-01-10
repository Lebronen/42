/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:12:12 by rshay             #+#    #+#             */
/*   Updated: 2023/01/10 19:26:47 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "include/mlx.h"
#include <stdio.h>

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	return (0);
}

int	clavier(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
	}
	
	return (0);
}

int	dive(int button, int x, int y, t_vars *vars)
{
	t_comp p = coord_to_comp(x, y, *vars);
	if (button == 1)
	{
		vars->x_min = vars->x_min * 1.03;
		vars->x_max = vars->x_max * 1.03;
		vars->y_min = vars->y_min * 1.03;
		vars->y_max = vars->y_max * 1.03;
		vars->move_x = p.r;
		vars->move_y = p.i;
	}
	else if (button == 3)
	{
		vars->x_min = vars->x_min / 1.03;
		vars->x_max = vars->x_max / 1.03;
		vars->y_min = vars->y_min / 1.03;
		vars->y_max = vars->y_max / 1.03;
		vars->move_x = p.r;
		vars->move_y = p.i;
	}
		put_fractale(vars->img, 75 , *vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0 );
	
	printf("%d\n", button);
	return (0);
}
