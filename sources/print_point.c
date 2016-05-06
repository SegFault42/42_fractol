/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:41:05 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/06 19:13:39 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pixel_put_to_image(t_all *all)
{
	all->r = (all->img_color & 0xFF0000) >> 16;
	all->g = (all->img_color & 0xFF00) >> 8;
	all->b = (all->img_color & 0xFF);
	if (all->endian == 0)
	{
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 2] = all->r;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 1] = all->g;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 0] = all->b;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 3] = 0x00;
	}
	else
	{
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 2] = all->b;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 1] = all->g;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 0] = all->r;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 3] = all->o;
	}
}

void	ft_pixel_put_to_image_colors(t_all *all)
{
	if (all->endian == 0)
	{
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 2] = all->r;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 1] = all->g;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 0] = all->b;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 3] = all->o;
	}
	else
	{
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 2] = all->b;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 1] = all->g;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 0] = all->r;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 3] = all->o;
	}
}

void	menu(t_all *all)
{
	mlx_string_put(MLX, WIN, 15, 10, GREEN, "Esc = Exit");
	mlx_string_put(MLX, WIN, 15, 25, GREEN, "+   = Luminosity +");
	mlx_string_put(MLX, WIN, 15, 40, GREEN, "-   = Luminosity -");
	mlx_string_put(MLX, WIN, 15, 55, GREEN, "0   = Reset");
	mlx_string_put(MLX, WIN, 15, 70, GREEN, "P   = Level +");
	mlx_string_put(MLX, WIN, 15, 85, GREEN, "O   = Level -");
	mlx_string_put(MLX, WIN, 15, 100, GREEN, ">   = Move Right");
	mlx_string_put(MLX, WIN, 15, 115, GREEN, "<   = Move Left");
	mlx_string_put(MLX, WIN, 15, 130, GREEN, "^   = Move Up");
	mlx_string_put(MLX, WIN, 15, 145, GREEN, "v   = Move Down");
	mlx_string_put(MLX, WIN, 15, 160, GREEN, "T  = Rotate Up");
	mlx_string_put(MLX, WIN, 15, 175, GREEN, "G  = Rotate Down");
	mlx_string_put(MLX, WIN, 15, 190, GREEN, "1  = Front view");
	mlx_string_put(MLX, WIN, 15, 205, GREEN, "2  = Top view");
}
