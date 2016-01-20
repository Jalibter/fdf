/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:56:53 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/20 14:48:45 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vrtce				*new_vertices(void)
{
	t_vrtce			*vertices;

	if (!(vertices = (t_vrtce *)malloc(sizeof(t_vrtce *))))
		malloc_error();
	vertices->vertex = (t_vector3){.x = 0, .y = 0, .z = 0};
	return (vertices);
}
