/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:15:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/27 09:16:12 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mlx(t_all *all)
{
	all->mlx_ptr = mlx_init();
	all->img_ptr = mlx_new_image(all->mlx_ptr, WIDTH, HEIGHT);
	all->data = mlx_get_data_addr(all->img_ptr, &all->bpp, &all->sizeline, &all->endian);
	all->win_ptr = mlx_new_window(all->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	all->img_color = mlx_get_color_value(all->mlx_ptr, GREEN);
}

void	init_julia(t_all *all)
{
	all->x1 = -1.6;
	all->x2 = 2;
	all->y1 = -1.2;
	all->y2 = 2;
	all->zoom = 400;
	all->max = 150;
}

void	init_mandelbrot(t_all *all)
{
	all->x1 = -2.1;
	all->x2 = 0.6;
	all->y1 = -1.2;
	all->y2 = 1.2;
	all->zoom = 200;
	all->max = 50;
}
