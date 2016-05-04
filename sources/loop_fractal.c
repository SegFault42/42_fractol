/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:10:33 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 16:48:00 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	loop_mandelbrot(t_all *all)
{
	while ((ft_sqrt(all->z_r)) + (ft_sqrt(all->z_i)) < 4 && all->i < all->max)
	{
		all->tmp = all->z_r;
		all->z_r = (ft_sqrt(all->z_r)) - ft_sqrt(all->z_i) + all->c_r;
		all->z_i = 2 * all->z_i * all->tmp + all->c_i;
		all->i++;
		color_fractal(all);
	}
}

void	loop_ship(t_all *all)
{
	while ((ft_sqrt(all->z_r)) + (ft_sqrt(all->z_i)) < 4 && all->i < all->max)
	{
		all->tmp = all->z_r;
		all->z_r = fabs((ft_sqrt(all->z_r) - (ft_sqrt(all->z_i)) + all->c_r));
		all->z_i = fabs(2 * all->z_i * all->tmp + all->c_i);
		all->i++;
		color_fractal(all);
	}
}
