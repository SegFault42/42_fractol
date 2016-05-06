/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:15:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/06 16:33:54 by rabougue         ###   ########.fr       */
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
	all->x1 = -1.499424;
	all->x2 = 0.6;
	all->y1 = -0.019518;
	all->y2 = 1.2;
	all->zoom = 14578.096738;
	all->max = 90;
	all->r2 = 249;
	all->g2 = 246;
	all->b2 = 10;
	all->o = 0;
}

void	init_julia(t_all *all)
{
	all->x1 = -0.398693;
	all->x2 = 2;
	all->y1 = -1.119590;
	all->y2 = 2;
	all->zoom = 427.967506;
	all->max = 50;
	all->c_r = 0;
	all->c_i = 0.750150;
	all->r2 = 15;
	all->g2 = 5;
	all->b2 = 8;
	all->o = 0;
	init_event(all);
}

void	init_ship(t_all *all)
{
	all->x1 = -1.810057;
	all->x2 = 0.6;
	all->y1 = -0.087011;
	all->y2 = 1.2;
	all->zoom = 5620.487370;
	all->max = 30;
	all->r2 = 0;
	all->g2 = 8;
	all->b2 = 13;
	all->o = 0;
}

void	init_tricorne(t_all *all)
{
	all->x1 = 0.871653;
	all->x2 = 0.6;
	all->y1 = -1.509791;
	all->y2 = 1.2;
	all->zoom = 20395995.138994;
	all->max = 190;
	all->r2 = 1;
	all->g2 = 1;
	all->b2 = 20;
	all->o = 0;
}
