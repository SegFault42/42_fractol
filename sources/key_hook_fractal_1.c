/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:15:54 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 13:50:23 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook_fractal_1(int keycode, t_all *all, void (*function)(t_all*))
{
	if (keycode == KEY_P)
		all->max += 5;
	else if (keycode == KEY_O && all->max >= 2)
		all->max -= 5;
	else if (keycode == KEY_RIGHT)
		all->x1 -= 1.1;
	else if (keycode == KEY_LEFT)
		all->x1 += 1.1;
	else if (keycode == KEY_UP)
		all->y1 += 1.1;
	else if (keycode == KEY_DOWN)
		all->y1 -= 1.1;
	else if (keycode == KEY_R)
		all->r2++;
	else if (keycode == KEY_G)
		all->g2++;
	else if (keycode == KEY_B)
		all->b2++;
	else if (keycode == KEY_E)
		all->r2--;
	key_hook_julia(keycode, all);
	function(all);
	key_hook_fractal_2(keycode, all, function);
	return (0);
}

int		key_hook_fractal_2(int keycode, t_all *all, void (*function)(t_all*))
{
	if (keycode == KEY_F)
		all->g2--;
	else if (keycode == KEY_V)
		all->b2--;
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	function(all);
	return (0);
}

int		check_fractal(int keycode, t_all *all)
{
	if (all->check_fractal == 1)
		key_hook_fractal_1(keycode, all, &draw_mandelbrot);
	else if (all->check_fractal == 2)
		key_hook_fractal_1(keycode, all, &draw_julia);
	else if (all->check_fractal == 3)
		key_hook_fractal_1(keycode, all, &draw_ship);
	else if (all->check_fractal == 4)
		key_hook_fractal_1(keycode, all, &draw_tricorne);
	return (0);
}

int		key_hook_julia(int keycode, t_all *all)
{
	if (keycode == KEY_SPACE)
		all->event.button_distorsion_julia++;
	if (keycode == KEY_F1)
		all->event.button_cross++;
	return (0);
}
