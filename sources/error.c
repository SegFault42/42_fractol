/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 23:44:51 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/29 11:04:44 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_arguments(int *argc, char **argv)
{
	ft_putendl("Usage : ");
	ft_putendl("./fractol -mandelbrot\n./fractol -julia");
	ft_putendl("./fractol -burning_ship\n./fractol -tricorne");
	exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
