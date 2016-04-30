/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/30 19:15:29 by rabougue         ###   ########.fr       */
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
# define BLK 0x000000
# define PURPLE 0x993299
# define DARK_GREY 0x3b3b3b
# define YLW 0xFFFF00

# define W 1280
# define H 720

typedef struct		s_all
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned long 	img_color;
	char			*data;
	int				sizeline;
	int				endian;
	int				bpp;
	int				x;
	int				y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;
	double			max;
	double			image_x;
	double			image_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			tmp;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_all;

int					j_slide(int null, double x, int y, t_all *all);
void				call_fractal_1(char **argv, t_all *all);
void				call_fractal_2(char **argv, t_all *all);
double				modulus(double a, double b);
int					mouse_hook_j(int button, int y, int x, t_all *all);
int					mouse_hook_m(int button, t_all *all);
int					check_arguments(int *argc, char **argv);
int					key_hook_m(int keycode, t_all *all);
int					key_hook_j(int keycode, t_all *all);
int					key_hook_ship(int keycode, t_all *all);
int					key_hook_tricorne(int keycode, t_all *all);
void				ft_pixel_put_to_image(t_all *all);
void				ft_pixel_put_to_image_colors(t_all *all);
void				draw_mandelbrot(t_all *all);
void				draw_tricorne(t_all *all);
void				draw_julia(t_all *all);
void				draw_ship(t_all *all);
void				clear_image(t_all *all);
void				init_tricorne(t_all *all);
void				init_mandelbrot(t_all *all);
void				init_julia(t_all *all);
void				init_ship(t_all *all);
void				init_mlx(t_all *all);

#endif
