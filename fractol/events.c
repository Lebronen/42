/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:12:12 by rshay             #+#    #+#             */
/*   Updated: 2023/01/10 22:39:03 by lebronen         ###   ########.fr       */
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
    printf("%d\n", keycode);
    
	
	return (0);
}

int	dive(int button, int x, int y, t_vars *vars)
{
    
	if (button == 1)
	{
        double pre_long = vars->x_max - vars->x_min;
        double longueur = pre_long / 2;
        double pre_large = vars->y_max - vars->y_max;
        double largeur = pre_large / 2;
        vars->x_min = x - longueur / 2;
        vars->x_max = x + longueur / 2;
        vars->y_min = y  - largeur / 2;
        vars->y_max = y + largeur / 2;
            
	}
	else if (button == 3)
	{
		double pre_long = vars->x_max - vars->x_min;
        double longueur = pre_long * 2;
        double pre_large = vars->y_max - vars->y_max;
        double largeur = pre_large * 2;
        vars->x_min = x - longueur * 2;
        vars->x_max = x + longueur * 2;
        vars->y_min = y  - largeur * 2;
        vars->y_max = y + largeur * 2;
	}
		put_fractale(vars->img, 75 , *vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0 );
	
	printf("%d\n", button);
	return (0);
}
