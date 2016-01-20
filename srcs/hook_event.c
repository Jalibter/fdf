/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:37:17 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/20 15:46:40 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (1);
}

int					key_hook(int keycode, t_env *e)
{
	if (keycode == KC_ESC)
		exit (0);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (1);
}
