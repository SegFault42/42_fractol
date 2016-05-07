/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 19:14:21 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 19:14:22 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_bird(t_all *all)
{
	all->x1 = -1.669874;
	all->y1 = -1.290668;
	all->zoom = 181.81818;
	all->max = 90;
	all->r2 = 11;
	all->g2 = 2;
	all->b2 = 0;
	all->o = 0;
}

void	init_space(t_all *all)
{
	all->x1 = -2.108539;
	all->y1 = -2.102668;
	all->zoom = 150;
	all->max = 80;
	all->c_r = -0.922300;
	all->c_i = 0.143250;
	all->r2 = 3;
	all->g2 = 3;
	all->b2 = 22;
	all->o = 0;
	init_event(all);
}

void	init_pylone(t_all *all)
{
	all->x1 = -0.315947;
	all->y1 = -0.351878;
	all->zoom = 918.994597;
	all->max = 30;
	all->r2 = 16;
	all->g2 = 65;
	all->b2 = 120;
	all->o = 0;
	all->c_r = 0.660000;
	all->c_i = 0.930150;
}

void	init_celtic(t_all *all)
{
	all->x1 = -1.669874;
	all->y1 = -1.290668;
	all->zoom = 181.81818;
	all->max = 90;
	all->r2 = 11;
	all->g2 = 2;
	all->b2 = 0;
	all->o = 0;
}
