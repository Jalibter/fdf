/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:03:32 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/29 15:18:38 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map				*read_map(int fd)
{
	t_map			*map;
	t_map			*ret;
	t_point			pos;
	char			*line;
	char			**line_split;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		malloc_error();
	pos = (t_point){0, 0, 0};
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strjoin(line, " ");
		line_split = ft_strsplit(line, ' ');
		pos.x = 0;
		while (line_split[pos.x] != 0)
		{
			map->pos.x = pos.x - ft_atoi(line_split[pos.x]);
			map->pos.y = pos.y - (pos.x + ft_atoi(line_split[pos.x]));
			if (!(map->next = (t_map *)malloc(sizeof(t_map))))
				malloc_error();
			map = map->next;
			++pos.x;
		}
		++pos.y;
	}
	map->next = NULL;
	return (ret);
}
