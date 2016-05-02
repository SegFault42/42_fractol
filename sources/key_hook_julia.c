/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:24:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/02 18:15:25 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook_julia_1(int keycode, t_all *all)
{
	static int		bool = 0;

	if (keycode == KEY_F1)
		bool = 0;
	if (keycode == KEY_F2)
		bool = 1;
	if (bool)
		mlx_hook(all->win_ptr, 6, 1L << 6, j_slide, (void *)all);
	if (keycode == KEY_V)
	{
		all->b2--;
		draw_julia(all);
	}
	if (keycode == KEY_F)
	{
		all->g2--;
		draw_julia(all);
	}
	key_hook_julia_2(keycode, all);
	return (0);
}

int		key_hook_julia_2(int keycode, t_all *all)
{
	if (keycode == KEY_EQUAL)
	{
		all->zoom *= 1.1;
		draw_julia(all);
	}
	if (keycode == KEY_MIN)
	{
		all->zoom /= 1.1;
		draw_julia(all);
	}
	if (keycode == KEY_P)
	{
		all->max += 10;
		draw_julia(all);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		all->max -= 10;
		draw_julia(all);
	}
	key_hook_julia_3(keycode, all);
	return (0);
}

int		key_hook_julia_3(int keycode, t_all *all)
{
	static double	speed = 0.1;

	if (keycode == KEY_RIGHT)
	{
		all->x1 -= speed;
		draw_julia(all);
	}
	if (keycode == KEY_LEFT)
	{
		all->x1 += speed;
		draw_julia(all);
	}
	if (keycode == KEY_UP)
	{
		all->y1 += speed;
		draw_julia(all);
	}
	if (keycode == KEY_DOWN)
	{
		all->y1 -= speed;
		draw_julia(all);
	}
	key_hook_julia_4(keycode, all);
	return (0);
}

int		key_hook_julia_4(int keycode, t_all *all)
{
	if (keycode == KEY_R)
	{
		all->r2++;
		draw_julia(all);
	}
	if (keycode == KEY_G)
	{
		all->g2++;
		draw_julia(all);
	}
	if (keycode == KEY_F)
	{
		all->g2--;
		draw_julia(all);
	}
	if (keycode == KEY_F)
	{
		all->g2--;
		draw_julia(all);
	}
	key_hook_julia_5(keycode, all);
	return (0);
}

int		key_hook_julia_5(int keycode, t_all *all)
{
	if (keycode == KEY_B)
	{
		all->b2++;
		draw_julia(all);
	}
	if (keycode == KEY_E)
	{
		all->r2--;
		draw_julia(all);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(all->mlx_ptr, all->img_ptr);
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
