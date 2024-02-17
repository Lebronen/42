#include "include/mlx.h"
#include "include/mlx_int.h"
#include "include/cub3d.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void init(t_data *img, void *mlx, void *mlx_win) {
    img->img = mlx_new_image(mlx, 800, 500);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);

    for (int i = 0; i < 800; i++) {
        my_mlx_pixel_put(img, i, 250, 0x00FF0000);
    }
    mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);


}

int main() {
    void	*mlx;
	t_data	img;
    void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 500, "Hello world!");
	init(&img, mlx, mlx_win);

	mlx_loop(mlx);

}