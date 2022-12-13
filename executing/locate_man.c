/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_man.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwchoi <sunwchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:08:40 by sunwchoi          #+#    #+#             */
/*   Updated: 2022/12/13 14:08:41 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	set_dir(t_game *game, char dir)
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

void	set_plane(t_game *game, char dir)
{
	int	plane_size;

	plane_size = 1;
	game->man.plane_x = 0;
	game->man.plane_y = 0;
	if (dir == 'N')
		game->man.plane_x = plane_size;
	else if (dir == 'S')
		game->man.plane_x = -1 * plane_size;
	else if (dir == 'E')
		game->man.plane_y = plane_size;
	else if (dir == 'W')
		game->man.plane_y = -1 * plane_size;
}

void	locate_man(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = -1;
	map = game->map;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'W' ||
				map[y][x] == 'S' || map[y][x] == 'N')
			{
				game->man.pos_x = x;
				game->man.pos_y = y;
				set_dir(game, map[y][x]);
				set_plane(game, map[y][x]);
				map[y][x] = '0';
				return ;
			}
		}
	}
}
