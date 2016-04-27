/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:04:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/27 23:55:17 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_julia(t_all *all)
{
	all->x = 0;
	all->y = 0;
	all->image_x = (all->x2 - all->x1) * all->zoom;
	all->image_y = (all->y2 - all->y1) * all->zoom;
	while (all->x < all->image_x)
	{
		all->y = 0;
		while (all->y < all->image_y)
		{
			all->c_r = -0.70;
			all->c_i = 0.27015;
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
					all->b += 0;
					all->g += 0;
					all->r += 100;
					ft_pixel_put_to_image_colors(all);
					}
				}
				else if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
				{
					all->b += 0;
					all->g += 0;
					all->b = all->i*255/all->max;
					all->img_color = mlx_get_color_value(all->mlx_ptr, all->b);
					ft_pixel_put_to_image(all);
				}
			}
			all->y++;
		}
		all->x++;
	}
}

void	draw_mandelbrot(t_all *all)
{
	all->x = 0;
	all->y = 0;
	all->image_x = (all->x2 - all->x1) * all->zoom;
	all->image_y = (all->y2 - all->y1) * all->zoom;
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
				if (all->i == all->max)
				{
					if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
					{
					all->b += 0;
					all->g += 0;
					all->r += 70;
					ft_pixel_put_to_image_colors(all);
					}
				}
				else if (all->x < W && all->y < H && all->x > 0 && all->y > 0)
				{
					all->r += 0;
					all->g += 0;
					all->b = all->i*255/all->max;
					all->img_color = mlx_get_color_value(all->mlx_ptr, all->b);
					ft_pixel_put_to_image(all);
				}
			}
			all->y++;
		}
		all->x++;
	}
}

int		main(int argc, char **argv)
{
	t_all	all;

	check_arguments(&argc, &(*argv));
	init_mlx(&all);
	if (ft_strcmp(argv[1], "-m") == 0)
	{
		init_mandelbrot(&all);
		draw_mandelbrot(&all);
		mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 0, 0);
		mlx_hook(all.win_ptr, 2, 3, key_hook_m, (void *)&all);
	}
	else if (ft_strcmp(argv[1], "-j") == 0)
	{
		init_julia(&all);
		draw_julia(&all);
		mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 0, 0);
		mlx_hook(all.win_ptr, 2, 3, key_hook_j, (void *)&all);
	}
	mlx_loop(all.mlx_ptr);
	return (0);
}
