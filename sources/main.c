#include "../includes/fractol.h"

void	fractal(t_image *img, t_xy *xy)
{
	float	x1 = -2.1;
	float	x2 = 0.6;
	float	y1 = -1.2;
	float	y2 = 1.2;
	int		image_x = WIDTH;
	int		image_y = HEIGHT;
	int		max = 50;
	int		zoom_x = image_x / (x2 - x1);
	int		zoom_y = image_y / (y2 - y1);
	int		x = 0;
	int		y = 0;

	int		c_r;
	int		c_i;
	int		z_r;
	int		z_i;
	int		i;

	for(x = 0; x < image_x; x++)
	{
		for(y = 0; y < image_y; y++)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
		}
	}
	int	tmp = z_r;
	z_r = (z_r * z_r) - (z_i * z_i) + c_r;
	z_i = 2 * z_i * tmp + c_i;
	i++;
	while (z_r * z_r + z_i * z_i < 4 && i < max)
	{
		if (i == max)
			ft_pixel_put_to_image(img, xy);
	}
}

int	main(void)
{
	t_mlx	mlx;
	t_image	im;
	t_xy	xy;

	mlx.mlx_ptr = mlx_init();
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	im.data = mlx_get_data_addr(mlx.img_ptr, &im.bpp, &im.sizeline, &im.endian);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	im.img_color = mlx_get_color_value(mlx.mlx_ptr, GREEN);
	fractal(&im, &xy);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
