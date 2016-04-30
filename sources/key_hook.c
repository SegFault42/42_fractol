/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:05:06 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/30 13:15:19 by rabougue         ###   ########.fr       */
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

int		mouse_hook_m(int button, t_all *all)
{
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

int		j_slide(int x, int y, int null, t_all *all)
{
	if (x > 0 && x <= W && y > 0 && y <= H)
	{
		printf("x = %d, y = %d\n", x, y);
	}
	return (0);
}

int		mouse_hook_j(int button, int x, int y, t_all *all)
{
		if (button == CLICK_LEFT)
		{
			clear_image(all);
			all->zoom *= 1.1;
			all->x1 /=1.165;
			all->y1 /=1.13;
			draw_julia(all);
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
			printf("x = %d, y = %d\n", all->mouse_x, all->mouse_y);
		}
		if (button == CLICK_RIGHT)
		{
			clear_image(all);
			all->zoom /= 1.1;
			draw_julia(all);
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		}
		if (button == CLICK_RIGHT && x > 0 && y > 0)
		{
			printf("x = %d, y = %d\n", all->mouse_x, all->mouse_y);
		}
	return (0);
}

int		key_hook_m(int keycode, t_all *all)
{
	static double speed = 0.1;

	if (keycode == KEY_1)
		speed = 0.0001;
	if (keycode == KEY_2)
		speed = 0.05;
	if (keycode == KEY_3)
		speed = 0.1;
	if (keycode == KEY_EQUAL)
	{
		clear_image(all);
		all->zoom *= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_MIN)
	{
		clear_image(all);
		all->zoom /= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_P)
	{
		clear_image(all);
		all->max += 10;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		printf("Iteration + = %f\n", all->max);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		clear_image(all);
		all->max -= 10;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		printf("Iteration - = %f\n", all->max);
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(all);
		all->x1 -= speed;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_LEFT)
	{
		clear_image(all);
		all->x1 += speed;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		clear_image(all);
		all->y1 += speed;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(all);
		all->y1 -= speed;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(all->mlx_ptr, all->img_ptr);
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		key_hook_j(int keycode, t_all *all)
{
	static double speed = 0.1;

	if (keycode == KEY_1)
		speed = 0.01;
	if (keycode == KEY_2)
		speed = 0.05;
	if (keycode == KEY_3)
		speed = 0.1;
	if (keycode == KEY_EQUAL)
	{
		clear_image(all);
		all->zoom *= 1.1;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_MIN)
	{
		clear_image(all);
		all->zoom /= 1.1;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_P)
	{
		clear_image(all);
		all->max += 50;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		clear_image(all);
		all->max -= 50;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(all);
		all->x1 -= speed;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_LEFT)
	{
		clear_image(all);
		all->x1 += speed;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		clear_image(all);
		all->y1 += speed;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(all);
		all->y1 -= speed;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(all->mlx_ptr, all->img_ptr);
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(EXIT_SUCCESS);
	}
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
