/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:41:05 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/25 19:40:01 by rabougue         ###   ########.fr       */
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
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 3] = 0x00;
	}
}
