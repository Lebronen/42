/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:27:26 by lebronen          #+#    #+#             */
/*   Updated: 2022/12/11 15:20:19 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef FRACTOL_H
 14 # define FRACTOL_H
 15 
 16 # include <math.h>
 17 
 18 # ifndef W
 19 # define W 1920
 20 # endif
 21 
 22 # ifndef H
 23 # define H 1080
 24 # endif
 25 
 26 typedef struct s_data
 27 {
 28     void    *img;
 29     char    *addr;
 30     int     bpp;
 31     int     line_l;
 32     int     endian;
 33 }       t_data;
 34 
 35 typedef struct s_comp
 36 {
 37     double      r;
 38     double      i;
 39 }       t_comp;
 40 
 41 typedef struct s_vars
 42 {
 43     void    *mlx;
 44     void    *win;
 45     t_data  *img;
 46     int     color;
 47     double  zoom;
 48     double  x_min;
 49     double  x_max;
 50     double  y_min;
 51     double  y_max;
 52 }       t_vars;
 53 
 54 t_comp  add_comp(t_comp a, t_comp b);
 55 t_comp  prod_comp(t_comp a, t_comp b);
 56 int     norme_comp(t_comp z);
 57 t_comp  coord_to_comp(int x, int y, t_vars vars);
 58 void    put_fractale(t_data *img, int max, t_vars vars);
 59 int     mandelbrot(t_comp c, int max);
 60 int     close(t_vars *vars);
 61 int     clavier(int keycode, t_vars *vars);
 62 int     dive(int button, int x, int y, t_vars *vars);
 63 
 64 #endif
