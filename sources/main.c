#include "../includes/fractol.h"

int	main(void)
{
	t_mlx	mlx;
	t_image	im;

	mlx.mlx_ptr = mlx_init();
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	im.data = mlx_get_data_addr(mlx.img_ptr, &im.bpp, &im.sizeline, &im.endian);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	im.img_color = mlx_get_color_value(mlx.mlx_ptr, WHITE);
	
	t_xy	xy;
	float	x1 = -2.1;
	float	x2 = 0.6;
	float	y1 = -1.2;
	float	y2 = 1.2;
	float		zoom = 250;
	float		max = 50;
	float		image_x = (x2 - x1) * zoom;
	float		image_y = (y2 - y1) * zoom;

	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		i;
	float		tmp;

	for(xy.x = 0; xy.x < image_x; xy.x++)
	{
		for(xy.y = 0; xy.y < image_y; xy.y++)
		{
			c_r = xy.x / zoom + x1;
			c_i = xy.y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < max)
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
				if (i == max)
					if (xy.x < WIDTH && xy.y < HEIGHT)
						if (xy.x > 0 && xy.y > 0)
							ft_pixel_put_to_image(&im, &xy);
			}
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
