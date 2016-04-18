#include "../includes/fractol.h"

void	clear_image(t_all *all)
{
	int		i;
	int		j;
	char	*data;

	i = 0;
	j = 0;
	data = mlx_get_data_addr(all->img_ptr, &all->bpp, &all->sizeline, &all->endian);
	while (i < (HEIGHT * all->sizeline))
	{
		data[i + 2] = 0;
		data[i + 1] = 0;
		data[i + 0] = 0;
		data[i + 3] = 0;
		i += 4;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}


int	key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_EQUAL)
	{
		clear_image(all);
		all->img_color = mlx_get_color_value(all->mlx_ptr, WHITE);
		printf("%f\n", all->zoom);
		all->zoom++;
		draw_fractal(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		ft_debug();
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
