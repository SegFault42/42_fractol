/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_fractal_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:13:49 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 00:53:05 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook_fractal_1(int keycode, t_all *all, void (*function)(t_all*))
{
	printf("zoom = %f, x1 = %f, y1 = %f, all->max = %f\n",
			all->zoom, all->x1, all->y1, all->max);
	printf("r2 = %u, g2 = %u, b2 = %u\n", all->r2, all->g2, all->b2);
	printf("c_r = %f, c_i = %f\n\n", all->c_r, all->c_i);
	if (keycode == KEY_P)
		all->max += 20;
	else if (keycode == KEY_O && all->max > 10)
		all->max -= 20;
	else if (keycode == KEY_RIGHT)
		move(all, -10, 0);
	else if (keycode == KEY_LEFT)
		move(all, 10, 0);
	else if (keycode == KEY_UP)
		move(all, 0, 10);
	else if (keycode == KEY_DOWN)
		move(all, 0, -10);
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

int		key_hook_julia(int keycode, t_all *all)
{
	if (keycode == KEY_SPACE)
		all->event.button_distorsion_julia++;
	if (keycode == KEY_F1)
		all->event.button_cross++;
	return (0);
}

int		key_hook_fractal_2(int keycode, t_all *all, void (*function)(t_all*))
{
	if (keycode == KEY_EQUAL)
		all->o -= 20;
	else if (keycode == KEY_MIN)
		all->o += 20;
	else if (keycode == KEY_F)
		all->g2--;
	else if (keycode == KEY_V)
		all->b2--;
	else if (keycode == KEY_F5)
		all->c_r -= 0.01;
	else if (keycode == KEY_F6)
		all->c_r += 0.01;
	else if (keycode == KEY_F7)
		all->c_i -= 0.01;
	else if (keycode == KEY_F8)
		all->c_i += 0.01;
	else if (keycode == KEY_0)
		check_fractal_init(all);
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_M)
		system("afplay sound/Sound.mp3&");
	else if (keycode == KEY_N)
		(system("killall afplay"));
	function(all);
	key_hook_fractal_3(keycode, all, function);
	return (0);
}

int		key_hook_fractal_3(int keycode, t_all *all, void (*function)(t_all*))
{
	if (keycode == KEY_1)
	{
		all->r2 = 2;
		all->g2 = 2;
		all->b2 = 2;
	}
	else if (keycode == KEY_2)
	{
		all->r2 = 0;
		all->g2 = 248;
		all->b2 = 248;
	}
	else if (keycode == KEY_0)
		check_fractal_init(all);
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	function(all);
	return (0);
}
