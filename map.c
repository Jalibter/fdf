/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:21:32 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/11 12:38:06 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3				*get_vertices_map(char **b_map, int width, int height)
{
	int				i;
	t_vec3			c;
	t_vec3			*vertices;

	i = 0;
	c.y = 0;
	c.z = 0;
	if (!(vertices = (t_vec3 *)malloc(sizeof(t_vec3) * (width * height))))
		return (NULL);
	while (c.y < height)
	{
		c.x = 0;
		while (c.x < width)
		{
			vertices[i] = {.x = c.x, .y = c.y, .z = ft_atoi(b_map[c.y][c.x])};
			while (b_map[c.y][c.x] != ' ' || b_map[c.y][c.x] != '\0')
				++c.x;
			++i;
			++c.z;
			++c.x;
		}
		++c.y;
	}
	return (vertices);
}
