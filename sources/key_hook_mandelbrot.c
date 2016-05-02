/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:15:54 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/02 21:19:54 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook_mandelbrot_1(int keycode, t_all *all)
{
	if (keycode == KEY_F)
	{
		all->g2--;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_V)
	{
		all->b2--;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(all->mlx_ptr, all->img_ptr);
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(EXIT_SUCCESS);
	}
	key_hook_mandelbrot_2(keycode, all);
	return (0);
}
int		key_hook_mandelbrot_2(int keycode, t_all *all)
{
	if (keycode == KEY_EQUAL)
	{
		all->zoom *= 1.1;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_MIN)
	{
		all->zoom /= 1.1;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_P)
	{
		all->max += 10;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_O && all->max >= 2)
	{
		all->max -= 10;
		draw_mandelbrot(all);
	}
	key_hook_mandelbrot_3(keycode, all);
	return (0);
}

int		key_hook_mandelbrot_3(int keycode, t_all *all)
{
	if (keycode == KEY_RIGHT)
	{
		all->x1 -= 1.1;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_LEFT)
	{
		all->x1 += 1.1;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_UP)
	{
		all->y1 += 1.1;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_DOWN)
	{
		all->y1 -= 1.1;
		draw_mandelbrot(all);
	}
	key_hook_mandelbrot_4(keycode, all, &draw_mandelbrot);
	return (0);
}

int		key_hook_mandelbrot_4(int keycode, t_all *all, void(*function)(t_all*))
{
	if (keycode == KEY_R)
	{
		all->r2++;
		function(all);
		//draw_mandelbrot(all);
	}
	if (keycode == KEY_G)
	{
		all->g2++;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_B)
	{
		all->b2++;
		draw_mandelbrot(all);
	}
	if (keycode == KEY_E)
	{
		all->r2--;
		draw_mandelbrot(all);
	}
	return (0);
}

void	check_fractal(char **argv, int keycode, t_all *all)
{
	if (ft_strcmp(argv[1], "-mandelbrot") == 0)
	{
		key_hook_mandelbrot_4(keycode, all, &draw_mandelbrot);
	}
}

/*int		key_hook_mandelbrot_5(int keycode, t_all *all)*/
/*{*/
/*}*/
