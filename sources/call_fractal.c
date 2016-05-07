/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:15:33 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 16:55:56 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	call_fractal_1(char **argv, t_all *all)
{
	init_zoom_tab(all);
	if (ft_strcmp(argv[1], "-mandelbrot") == 0)
	{
		init_mlx(all);
		all->check_fractal = 0;
		init_mandelbrot(all);
		draw_mandelbrot(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else if (ft_strcmp(argv[1], "-julia") == 0)
	{
		init_mlx(all);
		all->check_fractal = 1;
		init_julia(all);
		draw_julia(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
		mlx_hook(all->win_ptr, 6, 1L << 6, j_slide, (void *)all);
	}
	else
		call_fractal_2(argv, all);
}

void	call_fractal_2(char **argv, t_all *all)
{
	if (ft_strcmp(argv[1], "-burning_ship") == 0)
	{
		init_mlx(all);
		all->check_fractal = 2;
		init_ship(all);
		draw_ship(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else if (ft_strcmp(argv[1], "-tricorne") == 0)
	{
		init_mlx(all);
		all->check_fractal = 3;
		init_tricorne(all);
		draw_tricorne(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else
		call_fractal_3(argv, all);
}

void	call_fractal_3(char **argv, t_all *all)
{
	if (ft_strcmp(argv[1], "-bird_of_prey") == 0)
	{
		init_mlx(all);
		all->check_fractal = 4;
		init_bird(all);
		draw_bird(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else if (ft_strcmp(argv[1], "-space") == 0)
	{
		init_mlx(all);
		all->check_fractal = 5;
		init_space(all);
		draw_space(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else
		call_fractal_4(argv, all);
}

void	call_fractal_4(char **argv, t_all *all)
{
	if (ft_strcmp(argv[1], "-pylone") == 0)
	{
		init_mlx(all);
		all->check_fractal = 6;
		init_pylone(all);
		draw_pylone(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else if (ft_strcmp(argv[1], "-celtic") == 0)
	{
		init_mlx(all);
		all->check_fractal = 7;
		init_celtic(all);
		draw_celtic(all);
		mlx_mouse_hook(all->win_ptr, mouse_hook_zoom, (void *)all);
		mlx_hook(all->win_ptr, 2, 3, check_fractal, (void *)all);
	}
	else
		check_arguments();
}
