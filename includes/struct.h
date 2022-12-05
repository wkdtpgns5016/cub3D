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
	int		*memory;
	int		buffer[480][640];
	int		bytes_per_pixel;
	int		size_line;
	int		horizon;
	int		endian;
}	t_bg;

typedef struct s_wall
{
	void	*img_ptr[4];
	int		*texture[4];
	int		bytes_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_wall;

typedef struct	s_man
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	//int		**buf;
	//double	move_speed;
	//double	rot_speed;
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

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		line_height;
	int		side;

	int		draw_start;
	int		draw_end;
}	t_raycast;

typedef struct s_texture_info
{
	int		tex_num;
	int		tex_x;
	int		tex_y;
	double	texPos;
}	t_texture_info;

#endif
