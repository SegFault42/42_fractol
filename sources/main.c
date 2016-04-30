/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:04:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/30 11:11:22 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	modulus(double a, double b)
{
	 return sqrt(a*a + b*b);
}

void	call_fractal_1(char **argv, t_all *all)
{
	if (ft_strcmp(argv[1], "-burning_ship") == 0)
	{
		init_ship(all);
		draw_ship(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		mlx_hook(all->win_ptr, 2, 3, key_hook_ship, (void *)all);
	}
	else if (ft_strcmp(argv[1], "-mandelbrot") == 0)
	{
		init_mandelbrot(all);
		draw_mandelbrot(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		/*mlx_mouse_hook(all.win_ptr, mouse_hook_m, (void *)&all);*/
		mlx_hook(all->win_ptr, 2, 3, key_hook_m, (void *)all);
	}
	if (ft_strcmp(argv[1], "-julia") == 0)
	{
		init_julia(all);
		draw_julia(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		mlx_hook(all->win_ptr, 6, 2<<9, mouse_hook_j, (void *)&all);
		mlx_hook(all->win_ptr, 2, 3, key_hook_j, (void *)all);
	}
	call_fractal_2(argv, all);
}

void	call_fractal_2(char **argv, t_all *all)
{
	if (ft_strcmp(argv[1], "-tricorne") == 0)
	{
		init_tricorne(all);
		draw_tricorne(all);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		mlx_hook(all->win_ptr, 2, 3, key_hook_tricorne, (void *)all);
	}
}

int		main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		check_arguments(&argc, *(&argv));
	call_fractal_1(argv, &all);
	/*else if (argv[1] != '\0')*/
		/*check_arguments(&argc, *(&argv));*/
	mlx_loop(all.mlx_ptr);
	return (0);
}
