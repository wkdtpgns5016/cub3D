#ifndef EXECUTING_H
# define EXECUTING_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

#define KEY_LEFT 123
#define KEY_RIGHT 124

#define WIN_W 1920
#define WIN_H 1080

#include "../includes/struct.h"

#include "../minilibx/mlx.h"
#include "../error/error.h"

/*
typedef struct s_bg
{
	void	*img_ptr;
	char	*img_memory;
	int		bytes_per_pixel;
	int		size_line;
	int		endian;
}	t_bg;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr[4];
	t_bg	bg;
	int		color[2];
	char	**map;
}	t_game;
*/

#endif
