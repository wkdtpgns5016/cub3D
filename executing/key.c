#include "executing.h"
#include <stdio.h>

void	move(t_game *game, double step_x, double step_y)
{
	double	step;
	int	tmp;

	step = 0.5;
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

/*void	turn(t_game *game, int turn_rad)
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
*/
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
	/*else if (keycode == KEY_LEFT)
		turn(game, -1);
	else if (keycode == KEY_RIGHT)
		turn(game, 1);
	*/
	else if (keycode == KEY_ESC)
		exit(0);

	printf("x:%f,y:%f\n", game->man.pos_x, game->man.pos_y);
	return (0);
}

