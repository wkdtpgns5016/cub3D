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
	bg.bytes_per_pixel = bits_per_pixel / bits_per_byte;
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
	while (y <= WIN_H / bg.bytes_per_pixel)
	{
		idx = bg.bytes_per_pixel * x + bg.size_line * y;
		memory[idx] = game->color[0];
		idx = bg.bytes_per_pixel * x + bg.size_line * \
			  ((WIN_H / bg.bytes_per_pixel) - y);
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
	paint_background(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->bg.img_ptr, 0, 0);
	mlx_loop(game->mlx_ptr);
}
