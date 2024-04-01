#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l;
    int		bits_per_pixel;
    int		line_length;
	int		endian;
}           t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
}			t_vars;

typedef struct s_rays
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;

}			t_rays;






#endif