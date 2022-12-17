/* ************************************************************************** */
  2 /*                                                                            */
  3 /*                                                        :::      ::::::::   */
  4 /*   events.c                                           :+:      :+:    :+:   */
  5 /*                                                    +:+ +:+         +:+     */
  6 /*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
  7 /*                                                +#+#+#+#+#+   +#+           */
  8 /*   Created: 2022/12/14 19:12:12 by rshay             #+#    #+#             */
  9 /*   Updated: 2022/12/17 17:21:34 by rshay            ###   ########.fr       */
 10 /*                                                                            */
 11 /* ************************************************************************** */
 12 
 13 #include "fractol.h"
 14 #include "include/mlx.h"
 15 #include <stdio.h>
 16 
 17 int close(t_vars *vars)
 18 {
 19     mlx_destroy_window(vars->mlx, vars->win);
 20     return (0);
 21 }
 22 
 23 int clavier(int keycode, t_vars *vars)
 24 {
 25     if (keycode == 65307)
 26     {
 27         mlx_destroy_window(vars->mlx, vars->win);
 28         return (1);
 29     }
 30     else if (keycode == 119)
 31     {
 32         mlx_clear_window(vars->mlx, vars->win);
 33         vars->x_min /= 4;
 34         vars->x_max /= 2;
 35         vars->y_max *= 2;
 36         vars->y_min /= 2;
 37         put_fractale(vars->img, 75, *vars);
 38         mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
 39         return (2);
 40     }
 41     return (0);
 42 }
 43 /*
 44 int dive(int button, int x, int y, t_vars *vars)
 45 {
 46     if (button == 4)
 47     {
 48         
 49     }
 50     return (0);
 51 }
 52 */
