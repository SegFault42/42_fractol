/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:04:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 17:08:56 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	call_fractal_1(char **argv, t_all *all)
{
	init_zoom_tab(all);
	if (ft_strcmp(argv[1], "-mandelbrot") == 0)
	{
		all->check_fractal = 0;
		init_mandelbrot(all);
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else if (ft_strcmp(argv[1], "-julia") == 0)
	{
		all->check_fractal = 1;
		init_julia(all);
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
		mlx_hook(all->win_ptr, 6, 1L << 6, j_slide, (void *)all);
	}
	call_fractal_2(argv, all);
}

void	call_fractal_2(char **argv, t_all *all)
{
	if (ft_strcmp(argv[1], "-burning_ship") == 0)
	{
		all->check_fractal = 2;
		init_ship(all);
		draw_ship(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else if (ft_strcmp(argv[1], "-tricorne") == 0)
	{
		all->check_fractal = 3;
		init_tricorne(all);
		draw_tricorne(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
}

int		main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		check_arguments();
	call_fractal_1(argv, &all);
	mlx_loop(all.mlx_ptr);
	return (0);
}
