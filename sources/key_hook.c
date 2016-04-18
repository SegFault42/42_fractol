#include "../includes/fractol.h"

void	clear_image(void *pa, t_image *img)
{
	int		i;
	int		j;
	char	*data;

	i = 0;
	j = 0;
	data = mlx_get_data_addr(((t_mlx *)pa)->img_ptr, &img->bpp, &img->sizeline, &img->endian);
	while (i < (HEIGHT * img->sizeline))
	{
		data[i + 2] = 0;
		data[i + 1] = 0;
		data[i + 0] = 0;
		data[i + 3] = 0;
		i += 4;
	}
	/*mlx_put_image_to_window(((t_mlx *)pa)->mlx_ptr, ((t_mlx *)pa)->win_ptr, ((t_mlx *)pa)->img_ptr, 0, 0);*/
}


int	key_hook(int keycode, void *param, t_image *im)
{
	if (keycode == KEY_EQUAL)
	{
		clear_image(((t_all *)param), im);
		((t_image *)param)->img_color = mlx_get_color_value(((t_mlx *)param)->mlx_ptr, GREEN);
		/*draw_fractal(im, &move);*/
		mlx_put_image_to_window(((t_all *)param)->mlx->mlx_ptr, ((t_all *)param)->mlx->win_ptr, ((t_all *)param)->mlx->img_ptr, 0, 0);
		ft_debug();
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
