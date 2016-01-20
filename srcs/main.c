/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:34:01 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/20 15:16:31 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (1);
}

int					main(int argc, char **argv)
{
	t_vrtce			*vertices;
	t_env			e;

	if (argc != 2)
		arg_error();
	vertices = read_map(argv[1]);
	e.mlx = mlx_init();
	e.width = e.img.width = 1920;
	e.height = e.img.height = 1080;
	e.img.img = mlx_new_image(e.mlx, e.width, e.height);
	e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp, &e.img.size_line,
			&e.img.endian);
	e.win = mlx_new_window(e.mlx, e.width, e.height, ft_strjoin("FdF 42 | ",
				argv[1]));
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
