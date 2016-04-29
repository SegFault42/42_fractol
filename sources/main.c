/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:04:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/29 19:30:08 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	modulus(double a, double b)
{
	 return sqrt(a*a + b*b);
}

int		main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		check_arguments(&argc, *(&argv));
	if (ft_strcmp(argv[1], "-burning_ship") == 0)
	{
		init_ship(&all);
		draw_ship(&all);
		mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 0, 0);
		mlx_hook(all.win_ptr, 2, 3, key_hook_ship, (void *)&all);
	}
	else if (ft_strcmp(argv[1], "-mandelbrot") == 0)
	{
		init_mandelbrot(&all);
		draw_mandelbrot(&all);
		mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 0, 0);
		mlx_mouse_hook(all.win_ptr, mouse_hook_m, (void *)&all);
		mlx_hook(all.win_ptr, 2, 3, key_hook_m, (void *)&all);
	}
	else if (ft_strcmp(argv[1], "-julia") == 0)
	{
		init_julia(&all);
		draw_julia(&all);
		mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 0, 0);
		mlx_mouse_hook(all.win_ptr, mouse_hook_j, (void *)&all);
		mlx_hook(all.win_ptr, 2, 3, key_hook_j, (void *)&all);
	}
	else if (ft_strcmp(argv[1], "-tricorne") == 0)
	{
		init_tricorne(&all);
		draw_tricorne(&all);
		mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 0, 0);
		mlx_hook(all.win_ptr, 2, 3, key_hook_tricorne, (void *)&all);
	}
	else if (argv[1] != '\0')
		check_arguments(&argc, *(&argv));
	mlx_loop(all.mlx_ptr);
	return (0);
}
