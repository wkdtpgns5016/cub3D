#include "executing.h"

void	init_window(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_W, WIN_H, "cub3d");
	if (!game->win_ptr)
		ft_error("mlx error");
}

void	init_background(t_game *game)
{
	t_bg	bg;
	int	bits_per_byte;
	int	bits_per_pixel;

	bits_per_byte = 8;
	bg.img_ptr = mlx_new_image(game->mlx_ptr, WIN_W, WIN_H);
	bg.img_memory = mlx_get_data_addr(bg.img_ptr, &bits_per_pixel, \
		&bg.size_line, &bg.endian);
	bg.memory = (int *)bg.img_memory;
	bg.bytes_per_pixel = bits_per_pixel / bits_per_byte;
	bg.horizon = WIN_H / (2 * bg.bytes_per_pixel);
	game->bg = bg;
}

void	paint_background(t_game *game)
{
	t_bg	bg;
	int		*memory;
	int		x;
	int		y;
	int		idx;

	x = 0;
	y = 0;
	bg = game->bg;
	memory = (int *)bg.img_memory;
	while (y <= bg.horizon)
	{
		idx = bg.bytes_per_pixel * x + bg.size_line * y;
		memory[idx] = game->color[0];
		idx = bg.bytes_per_pixel * x + bg.size_line * \
			  (bg.horizon * 2 - y);
		memory[idx] = game->color[1];
		if (bg.bytes_per_pixel * x == bg.size_line)
		{
			x = 0;
			y++;
		}
		else 
			x++;
	}
}

void	executing(t_game *game)
{
	init_window(game);
	init_background(game);
	//paint_background(game);
	locate_man(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->bg.img_ptr, 0, 0);
	raycasting(game, &game->man, WIN_W);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->bg.img_ptr, 0, 0);
	mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_loop(game->mlx_ptr);
}
