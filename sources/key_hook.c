/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:05:06 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/24 01:20:08 by rabougue         ###   ########.fr       */
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
	data = mlx_get_data_addr(all->img_ptr, &all->bpp, &all->sizeline, &all->endian);
	while (i < (HEIGHT * all->sizeline))
	{
		data[i + 2] = 0;
		data[i + 1] = 0;
		data[i + 0] = 0;
		data[i + 3] = 0;
		i += 4;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
}

int		key_hook(int keycode, t_all *all)
{
	static t_move	move = {10, 10};

	if (keycode == KEY_EQUAL)
	{
		clear_image(all);
		all->img_color = mlx_get_color_value(all->mlx_ptr, GREEN);
		all->zoom += 10;
		draw_julia(all, &move);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_MIN)
	{
		clear_image(all);
		all->img_color = mlx_get_color_value(all->mlx_ptr, GREEN);
		all->zoom -= 10;
		draw_julia(all, &move);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		clear_image(all);
		all->img_color = mlx_get_color_value(all->mlx_ptr, GREEN);
		all->max += 10;
		printf("%f\n", all->max);
		draw_julia(all, &move);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_DOWN && all->max >= 2)
	{
		clear_image(all);
		all->img_color = mlx_get_color_value(all->mlx_ptr, GREEN);
		all->max -= 1;
		printf("%f\n", all->max);
		draw_julia(all, &move);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	}
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
