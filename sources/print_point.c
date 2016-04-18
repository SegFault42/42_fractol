/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:41:05 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/15 00:09:58 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pixel_put_to_image(t_all *all)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (all->img_color & 0xFF0000) >> 16;
	g = (all->img_color & 0xFF00) >> 8;
	b = (all->img_color & 0xFF);
	if (all->endian == 0)
	{
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 2] = r;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 1] = g;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 0] = b;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 3] = 0x00;
	}
	else
	{
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 2] = b;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 1] = g;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 0] = r;
		all->data[all->y * all->sizeline + all->x * all->bpp / 8 + 3] = 0x00;
	}
}
