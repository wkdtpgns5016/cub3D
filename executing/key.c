#include "executing.h"
#include <stdio.h>

void	move(t_game *game, double step_x, double step_y)
{
	double	step;
	int	tmp_x;
	int	tmp_y;

	step = 0.25;
	step_x *= step;
	step_y *= step;
	game->man.pos_y += step_y;
	tmp_y = floor(game->man.pos_y);
	if (!(0 <= tmp_y && game->map[tmp_y]))
	{
		game->man.pos_y -= step_y;
		return;
	}
	game->man.pos_x += step_x;
	tmp_x = floor(game->man.pos_x);
	if (!(0 <= tmp_x && tmp_x < ft_strlen(game->map[tmp_y])))
	{
		game->man.pos_x -= step_x;
		return;
	}
	if (game->map[tmp_y][tmp_x] == '1')
	{
		game->man.pos_y -= step_y;
		game->man.pos_x -= step_x;
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
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	init_background(game);
	raycasting(game, &game->man, WIN_W);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->bg.img_ptr, 0, 0);
	printf("pos_x:%f, %f\n  dir: %f, %f\n plane: %f, %f\n", game->man.pos_x, \
	game->man.pos_y, game->man.dir_x, game->man.dir_y, game->man.plane_x, game->man.plane_y);
	return (0);
}

