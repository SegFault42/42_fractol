/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/06 13:02:29 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include "./keyboard.h"

# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define WHITE		0xFFFFFF
# define BLK		0x000000
# define PURPLE		0x993299
# define DARK_GREY	0x3b3b3b
# define YLW		0xFFFF00

# define W			600
# define H			600

typedef struct		s_event
{
	int				button_distorsion_julia;
	int				button_cross;
	double			x_reel;
	double			y_reel;
	int				fd;
}					t_event;

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
	double			temp_x;
	double			temp_y;
	unsigned char	r2;
	unsigned char	g2;
	unsigned char	b2;
	int				check_fractal;
	t_event			event;
	void			(*zoom_tab[7])(struct s_all *);
}					t_all;
/*
** error.c
*/
int					check_arguments(void);
/*
** fractal.c
*/
void				draw_mandelbrot(t_all *all);
void				draw_julia(t_all *all);
void				draw_ship(t_all *all);
void				draw_tricorne(t_all *all);
void				draw_bird(t_all *all);
void				draw_space(t_all *all);
void				draw_buffalo(t_all *all);
/*
** init.c
*/
void				init_mlx(t_all *all);
void				init_julia(t_all *all);
void				init_mandelbrot(t_all *all);
void				init_ship(t_all *all);
void				init_tricorne(t_all *all);
void				init_bird(t_all *all);
void				init_space(t_all *all);
void				init_buffalo(t_all *all);
/*
** init_event.c
*/
void				init_zoom_tab(t_all *all);
void				init_event(t_all *all);
void				color_fractal(t_all *all);
/*
** loop_fractal.c
*/
void				loop_mandelbrot(t_all *all);
void				loop_julia(t_all *all);
void				loop_ship(t_all *all);
void				loop_tricorne(t_all *all);
void				loop_bird_of_pray(t_all *all);
void				loop_buffalo(t_all *all);
/*
** key_hook.c
*/
void				clear_image(t_all *all);
void				draw_cross(t_all *all, int x, int y, int color);
int					j_slide(int null, double x, int y, t_all *all);
int					save_stat(t_all *all);
/*
** mouse_hook.c
*/
int					mouse_hook_zoom(int button, int y, int x, t_all *all);
int					mouse_hook_j(int button, int y, int x, t_all *all);
int					mouse_hook_ship(int button, int y, int x, t_all *all);
int					mouse_hook_tricorne(int button, int y, int x, t_all *all);
/*
** key_hook_fractal_1.c
*/
int					key_hook_fractal_1(int key, t_all *all, void(*ft)(t_all *));
int					key_hook_julia(int keycode, t_all *all);
int					key_hook_fractal_2(int key, t_all *all, void(*ft)(t_all *));
int					check_fractal(int keycode, t_all *all);
int					check_fractal_init(t_all *all);
/*
** main.c
*/
void				call_fractal_1(char **argv, t_all *all);
void				call_fractal_2(char **argv, t_all *all);
void				call_fractal_3(char **argv, t_all *all);
/*
** print_point.c.c
*/
void				ft_pixel_put_to_image(t_all *all);
void				ft_pixel_put_to_image_colors(t_all *all);
void				menu(t_all *all);


int				pthread_test(t_all *all);
#endif
