/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 20:06:09 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/03 21:04:56 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_event(t_all *all)
{
	all->event.button_cross = 0;
	all->event.button_distorsion_julia = 0;
	all->event.x_reel = 0;
	all->event.y_reel = 0;
}
