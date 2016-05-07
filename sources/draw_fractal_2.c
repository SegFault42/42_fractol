/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 18:42:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 16:58:50 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_space(t_all *all)
{
	clear_image(all);
	all->x = 0;
	while (all->x < W)
	{
		all->y = 0;
		while (all->y < H)
		{
			all->z_r = all->x / all->zoom + all->x1;
			all->z_i = all->y / all->zoom + all->y1;
			all->i = 0;
			loop_bird_of_pray(all);
			all->y++;
		}
		all->x++;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}

void	draw_pylone(t_all *all)
{
	clear_image(all);
	all->x = 0;
	while (all->x < W)
	{
		all->y = 0;
		while (all->y < H)
		{
			while (all->y < H)
			{
				all->z_r = all->x / all->zoom + all->x1;
				all->z_i = all->y / all->zoom + all->y1;
				all->i = 0;
				loop_pylone(all);
				all->y++;
			}
			all->x++;
		}
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
}

void	draw_celtic(t_all *all)
{
	clear_image(all);
	all->x = 0;
	while (all->x < W)
	{
		all->y = 0;
		while (all->y < H)
		{
			all->c_r = all->x / all->zoom + all->x1;
			all->c_i = all->y / all->zoom + all->y1;
			all->z_r = 0;
			all->z_i = 0;
			all->i = 0;
			loop_celtic(all);
			all->y++;
		}
		all->x++;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}
