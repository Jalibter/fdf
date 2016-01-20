/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:03:32 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/20 14:48:23 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_vrtce				*read_map(char *file)
{
	t_vrtce			*vertices;
	t_vector3		pos;
	int				fd;
	char			*line;
	char			**line_split;

	vertices = new_vertices();
	pos = (t_vector3){.x = 0, .y = 0, .z = 0};
	if ((fd = open(file, O_RDONLY)) == -1)
		open_error(file);
	vertices->prev = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strjoin(line, " ");
		line_split = ft_strsplit(line, ' ');
		while (line_split[pos.x] != 0)
		{
			vertices->vertex = (t_vector3){.x = pos.x++,
				.y = ft_atoi(line_split[pos.z]), .z = pos.z};
			if (!(vertices->next = (t_vrtce *)malloc(sizeof(t_vrtce))))
				malloc_error();
			vertices->next->prev = vertices;
			vertices = vertices->next;
		}
		pos.x = 0;
		++pos.z;
	}
	return (vertices);
}
