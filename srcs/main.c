/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:34:01 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/25 13:14:32 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int					main(int argc, char **argv)
{
	t_vrtce			*vertices;
	t_env			e;
	int				fd;

	if (argc != 2)
		arg_error();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		open_error(argv[1]);
	vertices = read_map(fd);
	close (fd);
	e.mlx = mlx_init();
	e.width = e.img.width = 1920;
	e.height = e.img.height = 1080;
	e.img.img = mlx_new_image(e.mlx, e.width, e.height);
	e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp, &e.img.size_line,
			&e.img.endian);
	e.win = mlx_new_window(e.mlx, e.width, e.height, ft_strjoin("FdF 42 | ",
				argv[1]));
	t_vrtce *map_2d =  vertices_to_2d(vertices, &e);
	draw_map(&e, map_2d, 0xFF0000);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
