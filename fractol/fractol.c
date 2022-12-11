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

#include "minilibx-linux/mlx.h"
#include "fractol.h"
#include <stdio.h>

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
    
    void *mlx;
    void *mlx_win;
    t_data img;
    int i;
    int j;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 720, 460, "window");
    img.img = mlx_new_image(mlx, 720, 460);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    
    i = 0;
    
    while (i < 720)
    {
        j = 0;
        while (j < 460)
        {   
            my_mlx_pixel_put(&img, i , j,  0x00FF0000);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    
	mlx_loop(mlx);
    /*
   t_comp z;
   int x;
   z = coord_to_comp(720, 460, 460, 720);
   z = prod_comp(z, z);
   x = norme_comp(z);
   printf("%f + i%f et |z| = %d\n", z.r, z.i, x);
   */
}

t_comp coord_to_comp(int x, int y, int h, int w)
{
    t_comp pixel;
    pixel.r = (2.0 * (double)x / w - 1.0);
    pixel.i = (1.0 - 2.0 * (double)y / h);
    return pixel;
}

t_comp  mandelbrot(t_comp c, int max)
{
    if (norme_comp(c) == 0 || norme_comp(c) >= max)
        return (c);
    return add_comp(mandelbrot(prod_comp(c, c), max), mandelbrot(c, max));
    
}