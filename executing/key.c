#include "executing.h"
#include <stdio.h>

void	move(t_game *game, double step_x, double step_y)
{
	double	step;
	int	tmp;

	step = 0.25;
	step_x *= step;
	step_y *= step;
	game->man.pos_y += step_y;
	tmp = lround(game->man.pos_y);
	if (!(0 <= tmp && game->map[tmp]))
		game->man.pos_y -= step_y;
	game->man.pos_x += step_x;
	tmp = lround(game->man.pos_x);
	if (!(0 <= tmp && tmp < ft_strlen(game->map[lround(game->man.pos_y)])))
		game->man.pos_x -= step_x;
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
	char	*num;

	if (keycode == KEY_W)
		move(game, 0, -1);
	else if (keycode == KEY_S)
		move(game, 0, 1);
	else if (keycode == KEY_A)
		move(game, -1, 0);
	else if (keycode == KEY_D)
		move(game, 1, 0);
	else if (keycode == KEY_LEFT)
		rotate(game, -1);
	else if (keycode == KEY_RIGHT)
		rotate(game, 1);

	else if (keycode == KEY_ESC)
		exit(0);
	raycasting(game, &game->man, WIN_W);
	printf("pos_x:%f, %f\n  dir: %f, %f\n plane: %f, %f\n", game->man.pos_x, \
	game->man.pos_y, game->man.dir_x, game->man.dir_y, game->man.plane_x, game->man.plane_y);
	return (0);
}

