/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:37:17 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/20 15:46:40 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SPEED 30

int					key_hook(int keycode, t_params *params)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 123)
		params->offset.x -= SPEED;
	if (keycode == 124)
		params->offset.x += SPEED;
	if (keycode == 126)
		params->offset.y -= SPEED;
	if (keycode == 125)
		params->offset.y += SPEED;
	mlx_put_image_to_window(params->e.mlx, params->e.win, params->img.img,
		params->offset.x, params->offset.y);
	return (0);
}

int					loop_hook(t_params *params)
{
	return (0);
}
