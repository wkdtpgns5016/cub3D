#include "executing.h"

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
				game->man.x = x;
				game->man.y = y;
				game->man.head = map[y][x];
				game->man.radian = 0;
			}
		}
	}
}
