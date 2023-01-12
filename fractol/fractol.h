/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:27:26 by lebronen          #+#    #+#             */
/*   Updated: 2023/01/12 18:42:35 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef W
#  define W 500
# endif

# ifndef H
#  define H 500
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l;
	int		endian;
}			t_data;

typedef struct s_comp
{
	double	r;
	double	i;
}		t_comp;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
	int		color;
	double	zoom;
	double	px;
	double	py;
	double	move_x;
	double	move_y;
	char	d;
	int		max;
}			t_vars;

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

t_comp	add_comp(t_comp a, t_comp b);
t_comp	prod_comp(t_comp a, t_comp b);
int		norme_comp(t_comp z);
t_comp	coord_to_comp(int x, int y, t_vars vars);
void	put_fractale(t_vars vars, t_comp c, int x, int y);
int		fractale(t_comp c, t_comp z, int max);
int		close(t_vars *vars);
int		clavier(int keycode, t_vars *vars);
int		dive(int button, int x, int y, t_vars *vars);
int		str_comp(char *s1, char *s2);
double	ft_atoi(char *s);
double	atoi_dec(double nb, int neg, char *s);
double	pow_ten(double x, int i);
void	init(t_vars *vars, t_data *img);
void	loop(t_vars *vars, t_data *img);
void	set_c_and_z(t_comp *c, t_comp *z, t_vars vars, t_coord p);

#endif
