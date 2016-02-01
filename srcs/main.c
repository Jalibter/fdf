/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:34:01 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/29 15:17:47 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				init_params(t_params *params)
{
	params->zoom = 10;
	params->alt = 1;
	params->offset.x = WIDTH / 16;
	params->offset.y = HEIGHT / 9;
}

int					main(int argc, char **argv)
{
	int				fd;
	t_params		params;

	if (argc < 2)
		arg_error();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		file_error();
	read_map(&params, fd);
	params->env.mlx = mlx_init();
	params->env.win = mlx_new_window(params->env.mlx, WIDTH, HEIGHT,
						ft_strjoin("FdF @42 | ", argv[1]));
	init_params(&params);
	params.img.img = mlx_new_image(params.env.mlx, WIDTH, HEIGHT);
	params.img.data = mlx_get_data_addr(params.img.img, &params.img.bpp,
						&params.img.size_line, &params.img.endian);
	mlx_key_hook(&params.env.win, key_hook, params);
	ml_loop_hook();
	mlx_loop(params.env.mlx);
	return (0);
}
