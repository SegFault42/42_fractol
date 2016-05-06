/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:42:38 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/06 12:55:05 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_hook_zoom(int button, int x, int y, t_all *all)
{
	if (y > 0)
	{
		if (button == SCROLL_UP || button == CLICK_LEFT)
		{
			all->event.x_reel = (x / all->zoom) + all->x1;
			all->event.y_reel = (y / all->zoom) + all->y1;
			all->zoom *= 1.1;
			all->x1 = all->event.x_reel - (x / all->zoom);
			all->y1 = all->event.y_reel - (y / all->zoom);
			all->zoom_tab[all->check_fractal](all);
		}
		if (button == SCROLL_DOWN || button == CLICK_RIGHT)
		{
			all->event.x_reel = (x / all->zoom) + all->x1;
			all->event.y_reel = (y / all->zoom) + all->y1;
			all->zoom /= 1.1;
			all->x1 = all->event.x_reel - (x / all->zoom);
			all->y1 = all->event.y_reel - (y / all->zoom);
			all->zoom_tab[all->check_fractal](all);
		}
	}
	return (0);
}
