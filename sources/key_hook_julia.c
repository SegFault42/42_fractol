/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:24:35 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 00:03:10 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook_julia(int keycode, t_all *all)
{
	if (keycode == KEY_SPACE)
		all->event.button_distorsion_julia++;
	if (keycode == KEY_F1)
		all->event.button_cross++;
	return (0);
}
