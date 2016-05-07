/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:10:33 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 17:05:49 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	loop_celtic(t_all *all)
{
	while ((ft_sqrt(all->z_r)) + (ft_sqrt(all->z_i)) < 4 && all->i < all->max)
	{
		all->tmp = all->z_r;
		all->z_r = fabs(ft_sqrt(all->z_r) * all->z_r) - 3 * (ft_sqrt(all->z_i)
				* all->z_r) - all->c_i;
		all->z_i = 3 * (ft_sqrt(all->tmp) * all->z_i) - (ft_sqrt(all->z_i) *
				all->z_i) - all->c_r;
		all->i++;
		color_fractal(all);
	}
}
