/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:44:34 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/11 11:58:13 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "libft/libft.h"
# include "get_next_line.h"

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int 			height;
}					t_img;

typedef struct		s_env
{
	void 			*mlx;
	void			*win;
	int				height;
	int				width;
	t_img			img;
}					t_env;

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_vec3
{
	int				x;
	int				y;
	int				z;
}					t_vec3;

void				draw_line(t_img *img, t_vec2 a, t_vec2 b, int color);
float				ft_sqrt(float b);

#endif