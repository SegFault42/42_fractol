/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/27 09:22:38 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
# define YELLOW 0xFFFF00

# define WIDTH 1280
# define HEIGHT 720

typedef struct		s_all
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned long	img_color;
	char			*data;
	int				sizeline;
	int				endian;
	int				bpp;
	int				x;
	int				y;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			zoom;
	float			max;
	float			image_x;
	float			image_y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			i;
	float			tmp;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_all;

int					check_arguments(int *argc, char **argv);
int					key_hook_m(int keycode, t_all *all);
int					key_hook_j(int keycode, t_all *all);
void				ft_pixel_put_to_image(t_all *all);
void				init_mandelbrot(t_all *all);
void				draw_mandelbrot(t_all *all);
void				init_mandelbrot(t_all *all);
void				clear_image(t_all *all);
void				draw_julia(t_all *all);
void				init_julia(t_all *all);
void				init_mlx(t_all *all);

#endif
