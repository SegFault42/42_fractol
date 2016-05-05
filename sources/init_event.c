/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 20:06:09 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/05 21:26:09 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_zoom_tab(t_all *all)
{
	all->zoom_tab[0] = &draw_mandelbrot;
	all->zoom_tab[1] = &draw_julia;
	all->zoom_tab[2] = &draw_ship;
	all->zoom_tab[3] = &draw_tricorne;
	all->zoom_tab[4] = &draw_bird;
	all->zoom_tab[5] = &draw_space;
}

void	init_event(t_all *all)
{
	all->event.button_cross = 0;
	all->event.button_distorsion_julia = 0;
	all->event.x_reel = 0;
	all->event.y_reel = 0;
}

/*
** Le premier if sert a definir la couleur a l'interieur de Mandelbrot.
** Le else sert a definir la couleur de la forme. (Les valeurs a modifier sont
** dans le fichier init.c)
*/

void	color_fractal(t_all *all)
{
	if (all->i == all->max)
	{
		all->b = 1;
		all->r = 1;
		all->g = 1;
		ft_pixel_put_to_image_colors(all);
	}
	else
	{
		all->b = all->i * all->b2;
		all->r = all->i * all->r2;
		all->g = all->i * all->g2;
		all->img_color = mlx_get_color_value(all->mlx_ptr, all->b + all->r
				+ all->g);
		ft_pixel_put_to_image_colors(all);
	}
}
