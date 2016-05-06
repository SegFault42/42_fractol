/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 18:37:43 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 01:11:22 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		check_fractal_init(t_all *all)
{
	if (all->check_fractal == 0)
		init_mandelbrot(all);
	else if (all->check_fractal == 1)
		init_julia(all);
	else if (all->check_fractal == 2)
		init_ship(all);
	else if (all->check_fractal == 3)
		init_tricorne(all);
	else if (all->check_fractal == 4)
		init_bird(all);
	else if (all->check_fractal == 5)
		init_space(all);
	else if (all->check_fractal == 6)
		init_pylone(all);
	return (0);
}

int		check_fractal(int keycode, t_all *all)
{
	if (all->check_fractal == 0)
		key_hook_fractal_1(keycode, all, draw_mandelbrot);
	else if (all->check_fractal == 1)
		key_hook_fractal_1(keycode, all, &draw_julia);
	else if (all->check_fractal == 2)
		key_hook_fractal_1(keycode, all, &draw_ship);
	else if (all->check_fractal == 3)
		key_hook_fractal_1(keycode, all, &draw_tricorne);
	else if (all->check_fractal == 4)
		key_hook_fractal_1(keycode, all, &draw_bird);
	else if (all->check_fractal == 5)
		key_hook_fractal_1(keycode, all, &draw_space);
	else if (all->check_fractal == 6)
		key_hook_fractal_1(keycode, all, &draw_pylone);
	return (0);
}
