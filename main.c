#include "./includes/cub3d.h"

int main(int ac, char **av)
{
	t_game	*game;

	game = parsing(ac, av);
	executing(game);
}
