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

void	ft_pixel_put_to_image(t_image *img, t_xy *xy)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (img->img_color & 0xFF0000) >> 16;
	g = (img->img_color & 0xFF00) >> 8;
	b = (img->img_color & 0xFF);
	if (img->endian == 0)
	{
		img->data[xy->y * img->sizeline + xy->x * img->bpp / 8 + 2] = r;
		img->data[xy->y * img->sizeline + xy->x * img->bpp / 8 + 1] = g;
		img->data[xy->y * img->sizeline + xy->x * img->bpp / 8 + 0] = b;
		img->data[xy->y * img->sizeline + xy->x * img->bpp / 8 + 3] = 0x00;
	}
	else
	{
		img->data[xy->y * img->sizeline + xy->x * img->bpp / 8 + 2] = b;
		img->data[xy->y * img->sizeline + xy->x * img->bpp / 8 + 1] = g;
		img->data[xy->y * img->sizeline + xy->x * img->bpp / 8 + 0] = r;
		img->data[xy->y * img->sizeline + xy->x * img->bpp / 8 + 3] = 0x00;
	}
}
