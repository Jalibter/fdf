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

int					key_hook(int kc, t_params *params)
{
	if (kc == 53)
		exit(0);
	return (0);
}

int					loop_hook(t_params *params)
{
	if (params->redraw)
	{
		ft_bzero(params->img.data, WIDTH * HEIGHT * 4);
		// Draw map
		mlx_put_image_to_window(params->env.mlx, params->env.win,
								params->img.img.img, 0, 0);
		params->redraw = 0;
	}
	return (0);
}
