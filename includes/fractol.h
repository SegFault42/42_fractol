/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/15 21:04:31 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include "./keyboard.h"

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define PURPLE 0x993299
# define DARK_GREY 0x3b3b3b

# define WIDTH 1280
# define HEIGHT 720

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_mlx;

typedef struct		s_image
{
	unsigned long	img_color;
	char			*data;
	int				sizeline;
	int				endian;
	int				bpp;
}					t_image;

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

void	ft_pixel_put_to_image(t_image *img, t_xy *xy);

#endif
