/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 23:44:51 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/30 23:41:33 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_arguments(void)
{
	ft_putendl("Usage : ");
	ft_putendl("./fractol -mandelbrot\n./fractol -julia");
	ft_putendl("./fractol -burning_ship\n./fractol -tricorne");
	exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
