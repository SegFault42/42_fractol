/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:15:54 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 00:43:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook_fractal_1(int keycode, t_all *all, void (*function)(t_all*))
{
	if (keycode == KEY_F)
	{
		all->g2--;
		function(all);
	}
	if (keycode == KEY_V)
	{
		all->b2--;
		function(all);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(all->mlx_ptr, all->img_ptr);
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(EXIT_SUCCESS);
	}
	key_hook_fractal_2(keycode, all, function);
	return (0);
}

int		key_hook_fractal_2(int keycode, t_all *all, void (*function)(t_all*))
{
	if (keycode == KEY_P)
	{
		all->max += 10;
		function(all);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		all->max -= 10;
		function(all);
	}
	key_hook_fractal_3(keycode, all, function);
	return (0);
}

int		key_hook_fractal_3(int keycode, t_all *all, void (*function)(t_all*))
{
	if (keycode == KEY_RIGHT)
	{
		all->x1 -= 1.1;
	}
	if (keycode == KEY_LEFT)
	{
		all->x1 += 1.1;
	}
	if (keycode == KEY_UP)
	{
		all->y1 += 1.1;
	}
	if (keycode == KEY_DOWN)
	{
		all->y1 -= 1.1;
	}
	key_hook_fractal_4(keycode, all, function);
	return (0);
}

int		key_hook_fractal_4(int keycode, t_all *all, void (*function)(t_all*))
{
	if (keycode == KEY_R)
	{
		all->r2++;
		function(all);
	}
	if (keycode == KEY_G)
	{
		all->g2++;
		function(all);
	}
	if (keycode == KEY_B)
	{
		all->b2++;
		function(all);
	}
	if (keycode == KEY_E)
	{
		all->r2--;
		function(all);
	}
	key_hook_julia(keycode, all);
	return (0);
}

int		check_fractal(int keycode, t_all *all)
{
	if (all->check_fractal == 1)
		key_hook_fractal_1(keycode, all, &draw_mandelbrot);
	if (all->check_fractal == 2)
		key_hook_fractal_1(keycode, all, &draw_julia);
	if (all->check_fractal == 3)
		key_hook_fractal_1(keycode, all, &draw_ship);
	if (all->check_fractal == 4)
		key_hook_fractal_1(keycode, all, &draw_tricorne);
	return (0);
}
