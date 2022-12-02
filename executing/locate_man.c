#include "executing.h"

void	locate_dir(t_game *game, char dir)
{
	game->man.dir_x = 0;
	game->man.dir_y = 0;
	if (dir == 'N')
		game->man.dir_y = -1;
	else if (dir == 'S')
		game->man.dir_y = 1;
	else if (dir == 'E')
		game->man.dir_x = -1;
	else if (dir == 'W')
		game->man.dir_x = 1;
}

void	locate_man(t_game *game)
{
	int x;
	int y;
	char **map;

	y = -1;
	map = game->map;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'W'||
					map[y][x] == 'S'|| map[y][x] == 'N')
			{
				game->man.pos_x = x;
				game->man.pos_y = y;
				locate_dir(game, map[y][x]);
			}
		}
	}
}
