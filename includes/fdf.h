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

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				max_x;
	int				max_y;
	t_img			img;
}					t_env;

typedef struct		s_vector3
{
	int				x;
	int				y;
	int				z;
}					t_vector3;

typedef struct		s_vrtce
{
	t_vector3		vertex;
	struct s_vrtce	*next;
}					t_vrtce;

typedef struct		s_map
{
	t_vector3		**map;
	int				m_x;
	int				m_y;
}					t_map;

/*
** fdf_error.c
*/

void				arg_error(void);
void				malloc_error(void);
void				open_error(char *file);
void				map_error(void);

/*
** map.c
*/

t_vrtce				*read_map(int fd);
t_vrtce				*vertices_to_2d(t_vrtce *vertices, t_env *e);

/*
** draw.c
*/

void				put_pixel(t_img *img, t_vector3 p, int color);
void				draw_line(t_img *img, t_vector3 a, t_vector3 b, int color);
void				draw_map(t_env *e, t_vrtce *map, int color);

/*
** hook_event.c
*/

int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);

#endif
