#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_text
{
	char *element[6];
	char **map;
}	t_text;

typedef struct s_bg
{
	void	*img_ptr;
	char	*img_memory;
	int		bytes_per_pixel;
	int		size_line;
	int		endian;
}	t_bg;

typedef struct s_wall
{
	void	*img_ptr[4];
	int	width;
	int	height;
}	t_wall;

typedef struct s_man
{
	int	x;
	int	y;
	char head;
	int	radian;
}	t_man;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_wall	wall;	
	t_bg	bg;
	t_man	man;
	int		color[2];
	char	**map;
}	t_game;

#endif
