/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:04:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/25 20:10:25 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_julia(t_all *all, t_move *move)
{
	all->x1 = -1.6;
	all->x2 = 2;
	all->y1 = -1.2;
	all->y2 = 2;
	all->zoom = 400;
	all->max = 150;
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
					if (all->x < WIDTH && all->y < HEIGHT && all->x > 0 && all->y > 0)
					{
						all->img_color = mlx_get_color_value(all->mlx_ptr, BLACK);
						ft_pixel_put_to_image(all);
					}
				}
				else if (all->x < WIDTH && all->y < HEIGHT && all->x > 0 && all->y > 0)
				{
					all->r = 0;
					all->g = 110;
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

void	draw_mandelbrot(t_all *all, t_move *move)
{
	all->x1 = -2.1;
	all->x2 = 0.6;
	all->y1 = -1.2;
	all->y2 = 1.2;
	move->zoom = 200;
	move->max = 50;
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
					if (all->x < WIDTH && all->y < HEIGHT && all->x > 0 && all->y > 0)
						ft_pixel_put_to_image(all);
			}
			all->y++;
		}
		all->x++;
	}
}

void	init_mlx(t_all *all)
{
	all->mlx_ptr = mlx_init();
	all->img_ptr = mlx_new_image(all->mlx_ptr, WIDTH, HEIGHT);
	all->data = mlx_get_data_addr(all->img_ptr, &all->bpp, &all->sizeline, &all->endian);
	all->win_ptr = mlx_new_window(all->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	all->img_color = mlx_get_color_value(all->mlx_ptr, GREEN);
}

int		main(void)
{
	t_all	all;
	t_move	move;

	init_mlx(&all);
	draw_julia(&all, &move);
	mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 0, 0);
	mlx_hook(all.win_ptr, 2, 3, key_hook, (void *)&all);
	mlx_loop(all.mlx_ptr);
	return (0);
}
