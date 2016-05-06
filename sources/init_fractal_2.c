/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 21:40:06 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/06 16:45:37 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_bird(t_all *all)
{
	all->x1 = 0.557879;
	all->x2 = 0.6;
	all->y1 = -0.937647;
	all->y2 = 1.2;
	all->zoom = 73684.556769;
	all->max = 90;
	all->r2 = 3;
	all->g2 = 3;
	all->b2 = 0;
	all->o = 0;
}

void	init_space(t_all *all)
{
	all->x1 = 0.044690;
	all->x2 = 2;
	all->y1 = 0.4980;
	all->y2 = 2;
	all->zoom = 150;
	all->max = 80;
	all->c_r = -0.922300;
	all->c_i = 0.143250;
	all->r2 = 225;
	all->g2 = 216;
	all->b2 = 175;
	all->o = 0;
	init_event(all);
}

void	init_buffalo(t_all *all)
{
	all->x1 = -2.1;
	all->x2 = 0.6;
	all->y1 = -1.2;
	all->y2 = 1.2;
	all->zoom = 200;
	all->max = 50;
	all->r2 = 1;
	all->g2 = 50;
	all->b2 = 50;
	all->o = 0;
}
