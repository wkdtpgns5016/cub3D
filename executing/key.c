#include "executing.h"
#include <stdio.h>

void	move(t_game *game, int move_x, int move_y)
{
	game->man.x += move_x;
	if (!(0 <= game->man.x && game->man.x < ft_strlen(game->map[game->man.y])))
		game->man.x -= move_x;
	game->man.y += move_y;
	if (!(0 <= game->man.y && game->map[game->man.y]))
		game->man.y -= move_y;

}

void	turn(t_game *game, int turn_rad)
{
	char head[4];
	int	i;

	head[0] = 'N';
	head[1] = 'W';
	head[2] = 'S';
	head[3] = 'E';
	i = 0;
	while (i < 4 && head[i] != game->man.head)
			i++;
	game->man.radian += turn_rad;
	if (game->man.radian <= -90)
	{
		i--;
		game->man.radian = 0;
	}
	if (game->man.radian >= 90)
	{
		i++;
		game->man.radian = 0;
	}
	if (i < 0)
		i = 3;
	if (i == 4)
		i = 0;
	game->man.head = head[i];
}

int	key_press(int keycode, t_game *game)
{
	char	*num;

	if (keycode == KEY_W)
		move(game, STEP * 0, STEP * -1);
	else if (keycode == KEY_S)
		move(game, STEP * 0, STEP * 1);
	else if (keycode == KEY_A)
		move(game, STEP * -1, STEP * 0);
	else if (keycode == KEY_D)
		move(game, STEP * 1, STEP * 0);
	else if (keycode == KEY_LEFT)
		turn(game, TURN * -1);
	else if (keycode == KEY_RIGHT)
		turn(game, TURN * 1);
	else if (keycode == KEY_ESC)
		exit(0);

	printf("head:%c\n rad:%d\n x:%d,y:%d\n", game->man.head, game->man.radian, \
			game->man.x, game->man.y);
	return (0);
}

