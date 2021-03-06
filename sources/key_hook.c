/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:05:06 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 18:56:40 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	clear_image(t_all *all)
{
	int		i;
	int		j;
	char	*data;

	i = 0;
	j = 0;
	data = mlx_get_data_addr(all->img_ptr, &all->bpp, &all->sizeline,
	&all->endian);
	while (i < (H * all->sizeline))
	{
		data[i + 2] = 0;
		data[i + 1] = 0;
		data[i + 0] = 0;
		data[i + 3] = 0;
		i += 4;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}

void	draw_cross(t_all *all, int x, int y, int color)
{
	while (y <= H)
	{
		while (x <= W)
		{
			if (x == W / 2)
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, color);
			x++;
			if (y == H / 2)
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, color);
		}
		y++;
		x = 0;
	}
}

int		j_slide(int null, double x, int y, t_all *all)
{
	if (all->event.button_distorsion_julia % 2 != 0)
		if (x > 0 && x <= W && y > 0 && y <= H)
		{
			if (x < W / 2 && y < H / 2)
				all->c_r += 0.02;
			else if (x > W / 2 && y < H / 2)
				all->c_r -= 0.02;
			else if (x < W / 2 && y > H / 2)
				all->c_i += 0.02;
			else if (x > W / 2 && y > H / 2)
				all->c_i -= 0.02;
			draw_julia(all);
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
					all->img_ptr, 0, 0);
		}
	if (all->event.button_cross % 2 != 0)
		draw_cross(all, 0, 0, RED);
	else
		draw_julia(all);
	(void)null;
	return (0);
}
