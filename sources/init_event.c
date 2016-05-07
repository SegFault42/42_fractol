/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 20:06:09 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 16:56:32 by rabougue         ###   ########.fr       */
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
	all->zoom_tab[6] = &draw_pylone;
	all->zoom_tab[7] = &draw_celtic;
}

void	init_event(t_all *all)
{
	all->event.button_cross = 0;
	all->event.button_distorsion_julia = 0;
	all->event.x_reel = 0;
	all->event.y_reel = 0;
}

/*
** Les variables b, g, r servent a definir la couleur a l'interieur de
** Mandelbrot.
** Les variables all->b, all->g, all->r servent a definir la couleur
** de la forme. (Les valeurs a modifier sont dans le fichier init.c)
*/

void	color_fractal(t_all *all)
{
	all->b = 1;
	all->r = 1;
	all->g = 1;
	all->b = all->i * all->b2;
	all->r = all->i * all->r2;
	all->g = all->i * all->g2;
	all->img_color = mlx_get_color_value(all->mlx_ptr, all->b + all->r
			+ all->g);
	ft_pixel_put_to_image_colors(all);
}

void	move(t_all *all, double x, double y)
{
	all->x1 += (x / all->zoom);
	all->y1 += (y / all->zoom);
}
