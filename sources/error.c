/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 23:44:51 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/07 18:48:25 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_arguments(void)
{
	ft_putendl_fd("\033[31mUsage : \033[0m", 2);
	ft_putendl_fd("./fractol \033[32m-mandelbrot\033[0m", 2);
	ft_putendl_fd("./fractol \033[32m-julia\033[0m", 2);
	ft_putendl_fd("./fractol \033[32m-burning_ship\033[0m", 2);
	ft_putendl_fd("./fractol \033[32m-tricorne\033[0m", 2);
	ft_putendl_fd("./fractol \033[32m-bird_of_prey\033[0m", 2);
	ft_putendl_fd("./fractol \033[32m-space\033[0m", 2);
	ft_putendl_fd("./fractol \033[32m-pylone\033[0m", 2);
	ft_putendl_fd("./fractol \033[32m-celtic\033[0m", 2);
	exit(EXIT_FAILURE);
}
