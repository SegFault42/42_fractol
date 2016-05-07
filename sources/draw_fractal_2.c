/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 18:42:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 13:31:30 by rabougue         ###   ########.fr       */
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

void	draw_serpienski(t_all *all)
{
	clear_image(all);
	while (all->i < all->max)
	{
		if (abs(rand() % 3) == 0)
		{
			all->x = (all->x + all->ax) / 2;
			all->y = (all->y + all->ay) / 2;
		}
		else if (abs(rand() % 3) == 1)
		{
			all->x = (all->x + all->bx) / 2;
			all->y = (all->y + all->by) / 2;
		}
		else if (abs(rand() % 3) == 2)
		{
			all->x = (all->x + all->cx) / 2;
			all->y = (all->y + all->cy) / 2;
		}
		all->i++;
		color_fractal(all);
	}
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}
