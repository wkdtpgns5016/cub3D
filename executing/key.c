/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwchoi <sunwchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:05:18 by sunwchoi          #+#    #+#             */
/*   Updated: 2022/12/13 14:05:40 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	move(t_game	*game, double dir_x, double dir_y, int side)
{
	double	step;
	double	org_x;
	double	org_y;

	step = 0.2111;
	org_x = game->man.pos_x;
	org_y = game->man.pos_y;
	if (side == 0)
	{	
		if (game->map[(int)org_y][(int)(org_x + dir_x * step)] == '0')
			game->man.pos_x += dir_x * step;
		if (game->map[(int)(org_y + dir_y * step)][(int)org_x] == '0')
			game->man.pos_y += dir_y * step;
	}
	else
	{
		if (game->map[(int)org_y][(int)(org_x + dir_y * step)] == '0')
				game->man.pos_x += dir_y * step;
		if (game->map[(int)(org_y + dir_x * step)][(int)(org_x)] == '0')
				game->man.pos_y += dir_x * step;
	}
}

void	rotate(t_game *game, int rotate_flag)
{
	double	rad;
	double	org_x;
	double	org_y;

	rad = (double)1 / 24;
	rad *= rotate_flag;
	org_x = game->man.dir_x;
	org_y = game->man.dir_y;
	game->man.dir_x = org_x * cos(rad) - org_y * sin(rad);
	game->man.dir_y = org_x * sin(rad) + org_y * cos(rad);
	org_x = game->man.plane_x;
	org_y = game->man.plane_y;
	game->man.plane_x = org_x * cos(rad) - org_y * sin(rad);
	game->man.plane_y = org_x * sin(rad) + org_y * cos(rad);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move(game, game->man.dir_x, game->man.dir_y, 0);
	else if (keycode == KEY_S)
		move(game, -game->man.dir_x, -game->man.dir_y, 0);
	else if (keycode == KEY_A)
		move(game, -game->man.dir_x, game->man.dir_y, 1);
	else if (keycode == KEY_D)
		move(game, game->man.dir_x, -game->man.dir_y, 1);
	else if (keycode == KEY_LEFT)
		rotate(game, -1);
	else if (keycode == KEY_RIGHT)
		rotate(game, 1);
	else if (keycode == KEY_ESC)
		exit(0);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	init_background(game);
	paint_background(game);
	raycasting(game, &game->man, WIN_W);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->bg.img_ptr, 0, 0);
	return (0);
}
