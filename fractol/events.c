/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:12:12 by rshay             #+#    #+#             */
/*   Updated: 2023/01/11 17:39:44 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
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
	else if (keycode == 65361)
		vars->move_x += 0.1;
	else if (keycode == 65362)
		vars->move_y +=  0.1;
	else if (keycode == 65363)
		vars->move_x -= 0.1;
	else if (keycode == 65364)
		vars->move_y -= 0.1;
	put_fractale(vars->img, 45 , *vars);
    printf("%d\n", keycode);
    
	
	return (0);
}

int	dive(int button, int x, int y, t_vars *vars)
{
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
	put_fractale(vars->img, 45 , *vars);
	
	printf("%d\n", button);
	return (0);
}
