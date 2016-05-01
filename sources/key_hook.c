/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:05:06 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/02 01:14:00 by rabougue         ###   ########.fr       */
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

void	draw_cross(t_all *all)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= H)
	{
		while (x <= W)
		{
			if (x == W / 2)
			{
				all->temp_x = x;
				all->temp_y = y;
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, RED);
			}
			x++;
			if (y == H / 2)
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, RED);
		}
		y++;
		x = 0;
	}
}

int		mouse_hook_m(int button, t_all *all)
{
	if (button == SCROLL_UP)
	{
		all->zoom *= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (button == SCROLL_DOWN)
	{
		all->zoom /= 1.1;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	return (0);
}

int		j_slide(int null, double x, int y, t_all *all)
{
	if (x > 0 && x <= W && y > 0 && y <= H)
	{
		clear_image(all);
		if (x < W / 2 && y < H / 2)
			all->c_r += 0.02;
		else if (x > W / 2 && y < H / 2)
			all->c_r -= 0.02;
		else if (x < W / 2 && y > H / 2)
			all->c_i += 0.02;
		else if (x > W / 2 && y > H / 2)
			all->c_i -= 0.02;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	draw_cross(all);
	(void)null;
	return (0);
}

int		mouse_hook_j(int button, int x, int y, t_all *all)
{
	if (y > 0)
	{
		if (button == CLICK_LEFT)
		{
			clear_image(all);
			all->zoom *= 1.1;
			all->x1 /= 1.165;
			all->y1 /= 1.13;
			draw_julia(all);
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
					all->img_ptr, 0, 0);
		}
		if (button == CLICK_RIGHT)
		{
			clear_image(all);
			all->zoom /= 1.1;
			draw_julia(all);
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
					all->img_ptr, 0, 0);
		}
	}
	(void)x;
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
	if (keycode == KEY_R)
	{
		clear_image(all);
		all->r2++;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_G)
	{
		clear_image(all);
		all->g2++;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_B)
	{
		clear_image(all);
		all->b2++;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_E)
	{
		clear_image(all);
		all->r2--;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_F)
	{
		clear_image(all);
		all->g2--;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_V)
	{
		clear_image(all);
		all->b2--;
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	return (0);
}

int		key_hook_j(int keycode, t_all *all)
{
	static double	speed = 0.1;
	static int		pause = 1;

	printf("%d\n", pause);
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
		all->max += 10;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		clear_image(all);
		all->max -= 10;
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
	if (keycode == KEY_R)
	{
		clear_image(all);
		all->r2++;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_G)
	{
		clear_image(all);
		all->g2++;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_B)
	{
		clear_image(all);
		all->b2++;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_E)
	{
		clear_image(all);
		all->r2--;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_F)
	{
		clear_image(all);
		all->g2--;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_V)
	{
		clear_image(all);
		all->b2--;
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_F1)
		pause = 1;
	if (keycode == KEY_F2)
		pause = 0;
	if (pause == 0)
		mlx_hook(all->win_ptr, 6, 1L << 6, j_slide, (void *)all);
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
	if (keycode == KEY_R)
	{
		clear_image(all);
		all->r2++;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_G)
	{
		clear_image(all);
		all->g2++;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_B)
	{
		clear_image(all);
		all->b2++;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_E)
	{
		clear_image(all);
		all->r2--;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_F)
	{
		clear_image(all);
		all->g2--;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_V)
	{
		clear_image(all);
		all->b2--;
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	printf("Value RED = %d, Value GREEN = %d, Value BLUE = %d\n",
			all->r2, all->g2, all->b2);
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
		clear_image(all);
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
