/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:15:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/06 01:21:55 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mlx(t_all *all)
{
	all->mlx_ptr = mlx_init();
	all->img_ptr = mlx_new_image(all->mlx_ptr, W, H);
	all->data = mlx_get_data_addr(all->img_ptr, &all->bpp,
		&all->sizeline, &all->endian);
	all->win_ptr = mlx_new_window(all->mlx_ptr, W, H, "Fractol");
}

void	init_mandelbrot(t_all *all)
{
	init_mlx(all);
	all->x1 = -1.264379;
	all->x2 = 0.6;
	all->y1 = 0.373096;
	all->y2 = 1.2;
	all->zoom = 45752.312482;
	all->max = 90;
	all->r2 = 249;
	all->g2 = 246;
	all->b2 = 10;
}

void	init_julia(t_all *all)
{
	init_mlx(all);
	all->x1 = -0.201164;
	all->x2 = 2;
	all->y1 = -0.785149;
	all->y2 = 2;
	all->zoom = 758.170543;
	all->max = 70;
	all->c_r = -0.72000;
	all->c_i = 0.290150;
	all->r2 = 1;
	all->g2 = 3;
	all->b2 = 16;
	init_event(all);
}

void	init_ship(t_all *all)
{
	init_mlx(all);
	all->x1 = -1.867652;
	all->x2 = 0.6;
	all->y1 = -0.011895;
	all->y2 = 1.2;
	all->zoom = 73684.556769;
	all->max = 30;
	all->r2 = 0;
	all->g2 = 15;
	all->b2 = 10;
}

void	init_tricorne(t_all *all)
{
	init_mlx(all);
	all->x1 = -2.1;
	all->x2 = 0.6;
	all->y1 = -1.2;
	all->y2 = 1.2;
	all->zoom = 200;
	all->max = 50;
}
