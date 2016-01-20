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
	struct s_vrtce	*prev;
}					t_vrtce;

/*
** fdf_error.c
*/

void				arg_error(void);
void				malloc_error(void);
void				open_error(char *file);
void				map_error(void);

/*
** vertices.c
*/

t_vrtce				*new_vertices(void);

/*
** map.c
*/

t_vrtce				*read_map(char *file);

/*
** draw.c
*/

void				put_pixel(t_img *img, t_vector3 p, int color);
void				draw_line(t_img *img, t_vector3 a, t_vector3 b, int color);

/*
** hook_event.c
*/

int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);

#endif
