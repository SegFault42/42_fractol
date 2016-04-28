/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:05:06 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/28 23:45:13 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	clear_image(t_all *all)
{
	int		i;
	int		j;
	char	*data;

	i = 0;
	j = 0;
	data = mlx_get_data_addr(all->img_ptr, &all->bpp, &all->sizeline,
			&all->endian);
	while (i < (H * all->sizeline))
	{
		data[i + 2] = 0;
		data[i + 1] = 0;
		data[i + 0] = 0;
		data[i + 3] = 0;
		i += 4;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}

int		mouse_hook(int button, int x, int y, t_all *all)
{
	x = W;
	y = H;

	if (button == SCROLL_UP)
	{
		clear_image(all);
		all->zoom *= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (button == SCROLL_DOWN)
	{
		clear_image(all);
		all->zoom /= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
		return (0);
}

int		key_hook_m(int keycode, t_all *all)
{
	if (keycode == KEY_EQUAL)
	{
		clear_image(all);
		all->zoom *= 1.1;
		/*all->x2 /= all->x2 + 2;*/
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_MIN)
	{
		clear_image(all);
		all->zoom /= 1.1;
		/*all->x2 *= 3;*/
		/*all->y2 = 0;*/
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_P)
	{
		clear_image(all);
		all->max += 1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		clear_image(all);
		all->max -= 1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(all);
		all->x1 *= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_LEFT)
	{
		clear_image(all);
		all->x1 /= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		clear_image(all);
		all->y1 /= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(all);
		all->y1 *= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	/*printf("zoom = %f\n", all->zoom);*/
	return (0);
}

int		key_hook_j(int keycode, t_all *all)
{
	if (keycode == KEY_EQUAL)
	{
		clear_image(all);
		all->zoom += 10;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_MIN)
	{
		clear_image(all);
		all->zoom -= 10;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		clear_image(all);
		all->max += 1;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_DOWN && all->max >= 2)
	{
		clear_image(all);
		all->max -= 1;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int		key_hook_ship(int keycode, t_all *all)
{
	if (keycode == KEY_EQUAL)
	{
		clear_image(all);
		all->zoom *= 1.1;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_MIN)
	{
		clear_image(all);
		all->zoom /= 1.1;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_P)
	{
		clear_image(all);
		all->max += 1;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		clear_image(all);
		all->max -= 1;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(all);
		all->x1 *= 1.1;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_LEFT)
	{
		clear_image(all);
		all->x1 /= 1.1;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		clear_image(all);
		all->y1 /= 1.1;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(all);
		all->y1 *= 1.1;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int		key_hook_tricorne(int keycode, t_all *all)
{
	if (keycode == KEY_EQUAL)
	{
		clear_image(all);
		all->zoom *= 1.1;
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_MIN)
	{
		clear_image(all);
		all->zoom /= 1.1;
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_P)
	{
		clear_image(all);
		all->max += 1;
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		clear_image(all);
		all->max -= 1;
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(all);
		all->x1 *= 1.1;
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_LEFT)
	{
		clear_image(all);
		all->x1 /= 1.1;
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		clear_image(all);
		all->y1 /= 1.1;
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(all);
		all->y1 *= 1.1;
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
