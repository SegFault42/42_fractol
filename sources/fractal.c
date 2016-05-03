/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 21:15:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 01:13:28 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandelbrot(t_all *all)
{
	clear_image(all);
	all->x = 0;
	all->image_x = W;
	all->image_y = H;
	while (all->x < all->image_x)
	{
		all->y = 0;
		while (all->y < all->image_y)
		{
			all->c_r = all->x / all->zoom + all->x1;
			all->c_i = all->y / all->zoom + all->y1;
			all->z_r = 0;
			all->z_i = 0;
			all->i = 0;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && all->i
					< all->max)
			{
				all->tmp = all->z_r;
				all->z_r = (all->z_r * all->z_r) - (all->z_i * all->z_i)
			+ all->c_r;
				all->z_i = 2 * all->z_i * all->tmp + all->c_i;
				all->i++;
				all->b = all->i + all->b2;
				all->r = all->i * all->r2;
				all->g = all->i * all->g2;
				all->img_color = mlx_get_color_value(all->mlx_ptr,
						all->b + all->r * all->g);
				ft_pixel_put_to_image_colors(all);
			}
			all->y++;
		}
		all->x++;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}

void	draw_julia(t_all *all)
{
	clear_image(all);
	all->x = 0;
	all->image_x = W;
	all->image_y = H;
	while (all->x < all->image_x)
	{
		all->y = 0;
		while (all->y < all->image_y)
		{
			all->z_r = all->x / all->zoom + all->x1;
			all->z_i = all->y / all->zoom + all->y1;
			all->i = 0;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && all->i
					< all->max)
			{
				all->tmp = all->z_r;
				all->z_r = (all->z_r * all->z_r) - (all->z_i * all->z_i)
				+ all->c_r;
				all->z_i = 2 * all->z_i * all->tmp + all->c_i;
				all->i++;
				if (all->i == all->max)
				{
					if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
					{
						all->b = 1;
						all->r = 1;
						all->g = 1;
						all->img_color = mlx_get_color_value(all->mlx_ptr,
								all->b * all->r * all->g);
						ft_pixel_put_to_image_colors(all);
					}
				}
				else if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
				{
					all->b = all->i + all->b2;
					all->r = all->i * all->r2;
					all->g = all->i * all->g2;
					all->img_color = mlx_get_color_value(all->mlx_ptr,
							all->b + all->r * all->g);
					ft_pixel_put_to_image_colors(all);
				}
			}
			all->y++;
		}
		all->x++;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}

void	draw_ship(t_all *all)
{
	clear_image(all);
	all->x = 0;
	all->image_x = W;
	all->image_y = H;
	while (all->x < all->image_x)
	{
		all->y = 0;
		while (all->y < all->image_y)
		{
			all->c_r = all->x / all->zoom + all->x1;
			all->c_i = all->y / all->zoom + all->y1;
			all->z_r = 0;
			all->z_i = 0;
			all->i = 0;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && all->i
					< all->max)
			{
				all->tmp = all->z_r;
				all->z_r = fabs((all->z_r * all->z_r) - (all->z_i * all->z_i)
				+ all->c_r);
				all->z_i = fabs(2 * all->z_i * all->tmp + all->c_i);
				all->i++;
				if (all->i == all->max)
				{
					if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
					{
						all->b = 1;
						all->r = 1;
						all->g = 1;
						all->img_color = mlx_get_color_value(all->mlx_ptr,
								all->b * all->r * all->g);
						ft_pixel_put_to_image_colors(all);
					}
				}
				else if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
				{
					all->b = all->i + all->b2;
					all->r = all->i * all->r2;
					all->g = all->i * all->g2;
					all->img_color = mlx_get_color_value(all->mlx_ptr,
							all->b + all->r * all->g);
					ft_pixel_put_to_image_colors(all);
				}
			}
			all->y++;
		}
		all->x++;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}

void	draw_tricorne(t_all *all)
{
	clear_image(all);
	all->x = 0;
	all->image_x = W;
	all->image_y = H;
	while (all->x < all->image_x)
	{
		all->y = 0;
		while (all->y < all->image_y)
		{
			all->c_r = all->x / all->zoom + all->x1;
			all->c_i = all->y / all->zoom + all->y1;
			all->z_r = 0;
			all->z_i = 0;
			all->i = 0;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && all->i
					< all->max)
			{
				all->tmp = all->z_r;
				all->z_r = (all->z_r * all->z_r) - (all->z_i * all->z_i)
				+ all->c_r;
				all->z_i = -(2 * all->z_i * all->tmp + all->c_i);
				all->i++;
				if (all->i == all->max)
				{
					if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
					{
						all->img_color = mlx_get_color_value(all->mlx_ptr, BLK);
						ft_pixel_put_to_image_colors(all);
					}
				}
				else if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
				{
					all->b = all->i * 255 / all->max;
					all->r += all->i * 255 / all->max;
					all->g += all->i * 255 / all->max;
					all->img_color = mlx_get_color_value(all->mlx_ptr,
							all->b * all->r * all->g);
					ft_pixel_put_to_image(all);
				}
			}
			all->y++;
		}
		all->x++;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}
