/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:22:09 by lebronen          #+#    #+#             */
/*   Updated: 2022/12/11 15:36:04 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx.h"
 14 #include "fractol.h"
 15 
 16 void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
 17 {
 18     char    *dst;
 19 
 20     dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
 21     *(unsigned int *)dst = color;
 22 }
 23 
 24 int main(void)
 25 {
 26     t_vars      vars;
 27     t_data      img;
 28 
 29     vars.mlx = mlx_init();
 30     vars.win = mlx_new_window(vars.mlx, W, H, "window");
 31     img.img = mlx_new_image(vars.mlx, W, H);
 32     img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
 33     vars.img = &img;
 34     vars.color = 0;
 35     vars.zoom = 1;
 36     vars.x_min = -2;
 37     vars.x_max = 1;
 38     vars.y_max = 1;
 39     vars.y_min = -1;
 40     put_fractale(&img, 75, vars);
 41     mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
 42     mlx_hook(vars.win, 17, 1L << 0, close, &vars);
 43     mlx_hook(vars.win, 2, 1L << 0, clavier, &vars);
 44     //mlx_mouse_hook(vars.win, dive, &vars);
 45     mlx_loop(vars.mlx);
 46 }
 47 
 48 void    put_fractale(t_data *img, int max, t_vars vars)
 49 {
 50     int     x;
 51     int     y;
 52     t_comp  c;
 53     int     i;
 54 
 55     x = 0;
 56     while (x < W)
 57     {
 58         y = 0;
 59         while (y < H)
 60         {
 61             c = coord_to_comp(x, y, vars);
 62             i = mandelbrot(c, max);
 63             if (i != max)
 64                 my_mlx_pixel_put(img, x, y, (i * 0xAB42EFFF) % 0xFFFFFFFF);
 65             y++;
 66         }
 67         x++;
 68     }
 69 }
 70 
 71 t_comp  coord_to_comp(int x, int y, t_vars vars)
 72 {
 73     t_comp  pixel;
	 
	pixel.r = vars.x_min + (vars.x_max - vars.x_min) * x / (W - 1);
 76     pixel.i = vars.y_min + (vars.y_max - vars.y_min) * y / (H - 1);
 77     return (pixel);
 78 }
 79 
 80 int mandelbrot(t_comp c, int max)
 81 {
 82     t_comp  z;
 83     int     i;
 84 
 85     i = 0;
 86     z.r = 0;
 87     z.i = 0;
 88     while (i < max && norme_comp(z) < 4)
 89     {
 90         z = add_comp(prod_comp(z, z), c);
 91         i++;
 92     }
 93     return (i);
 94 
