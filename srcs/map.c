/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:03:32 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/25 13:49:54 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_vrtce				*read_map(int fd)
{
	t_vrtce			*vertices;
	t_vrtce			*ret;
	t_vector3		pos;
	char			*line;
	char			**line_split;

	if (!(vertices = (t_vrtce *)malloc(sizeof(t_vrtce))))
		malloc_error();
	ret = vertices;
	pos = (t_vector3){.x = 0, .y = 0, .z = 0};
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strjoin(line, " ");
		line_split = ft_strsplit(line, ' ');
		while (line_split[pos.x] != 0)
		{
			vertices->vertex = (t_vector3){.x = pos.x,
				.y = pos.z, .z = ft_atoi(line_split[pos.x])};
			++pos.x;
			if (!(vertices->next = (t_vrtce *)malloc(sizeof(t_vrtce))))
				malloc_error();
			vertices = vertices->next;
		}
		pos.x = 0;
		++pos.z;
	}
	return (ret);
}

t_map				vertices_to_2d(t_vrtce *vertices, t_env *e)
{
	t_vrtce			map;

	if (!(map = (t_map)sizeof(t_map)))
		malloc_error();
	return (map);
}
