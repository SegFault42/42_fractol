/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 23:44:51 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/25 11:59:51 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*void	draw_fractal(char **argv)*/
/*{*/
	/*if (argv[1] == "-m")*/
		/*draw_mandelbrot();*/
	/*else if (argv[1] == "-j")*/
		/*draw_julia();*/
/*}*/

int	check_arguments(int *argc, char **argv)
{
	if (*argc != 2)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" [-m mandelbrot | -j julia]");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

