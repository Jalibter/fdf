#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "libft.h"
# include "get_next_line.h"
# include "key_list.h"

/*
** Window define
*/

# define WIDTH 1920
# define HEIGHT 1080

/*
** Data types
*/

typedef struct	s_v2
{
	int			x;
	int			y;
}				t_v2;

typedef struct	s_v3
{
	int			x;
	int			y;
	int			z;
}				t_v3;

typedef struct	s_map
{
	t_v3		**vertices;
	t_v3		max;
}				t_map;

/*
** Window data
*/

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_params
{
	t_env		env;
	t_map		map;
	t_img		img;
	int			alt;
	int			zoom;
	int			redraw;
	t_v2		offset;
	float		adj;
}				t_params;

/*
** hooks.c
*/

int					key_hook(int kc, t_params *params);

/*
** error.c
*/

void				arg_error();
void				malloc_error();
void				file_error(char *file);
void				read_error();
void				map_error();

/*
** map.c
*/

void				read_map(t_params *params, int fd);

/*
** draw.c
*/

void				draw_line(t_img *img, t_v2 a, t_v2 b, int color);

#endif
