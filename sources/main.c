#include "../includes/fractol.h"

void	draw_fractal(t_image *im, t_move *move)
{
	t_xy	xy;

	move->x1 = -2.1;
	move->x2 = 0.6;
	move->y1 = -1.2;
	move->y2 = 1.2;
	move->zoom = 200;
	move->max = 50;
	xy.x = 0;
	xy.y = 0;
	move->image_x = (move->x2 - move->x1) * move->zoom;
	move->image_y = (move->y2 - move->y1) * move->zoom;

	while (xy.x < move->image_x)
	{
		xy.y = 0;
		while (xy.y < move->image_y)
		{
			move->c_r = xy.x / move->zoom + move->x1;
			move->c_i = xy.y / move->zoom + move->y1;
			move->z_r = 0;
			move->z_i = 0;
			move->i = 0;
			while (move->z_r * move->z_r + move->z_i * move->z_i < 4 && move->i
			< move->max)
			{
				move->tmp = move->z_r;
				move->z_r = (move->z_r * move->z_r) - (move->z_i * move->z_i)
				+ move->c_r;
				move->z_i = 2 * move->z_i * move->tmp + move->c_i;
				move->i++;
				if (move->i == move->max)
					if (xy.x < WIDTH && xy.y < HEIGHT && xy.x > 0 && xy.y > 0)
						ft_pixel_put_to_image(im, &xy);
			}
			xy.y++;
		}
		xy.x++;
	}
}

void	init_mlx(t_mlx *mlx, t_image *im)
{
	mlx->mlx_ptr = mlx_init();
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	im->data = mlx_get_data_addr(mlx->img_ptr, &im->bpp, &im->sizeline, &im->endian);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	im->img_color = mlx_get_color_value(mlx->mlx_ptr, PURPLE);
}

int	main(void)
{
	t_mlx	mlx;
	t_image	im;
	t_move	move;

	init_mlx(&mlx, &im);
	draw_fractal(&im, &move);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 2, 3, key_hook, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
