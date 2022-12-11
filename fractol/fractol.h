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
# define FRACTOL_H

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}       t_data;

typedef struct s_comp
{
    double r;
    double i;
}       t_comp;

t_comp  add_comp(t_comp a, t_comp b);
t_comp prod_comp(t_comp a, t_comp b);
int norme_comp(t_comp z);
t_comp coord_to_comp(int x, int y, int h, int w);
t_comp mandelbrot(t_comp c, int max);

#endif