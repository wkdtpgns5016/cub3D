#include "executing.h"
#include "../includes/struct.h"

int	get_texture_num(t_man *man, t_raycast *raycast)
{
	int	tex_num;

	if (raycast->side == 0 && raycast->ray_dir_x > 0)
		tex_num = EA;
	else if (raycast->side == 0 && raycast->ray_dir_x < 0)
		tex_num = WE;
	if (raycast->side == 1 && raycast->ray_dir_y > 0)
		tex_num = SO;
	else if (raycast->side == 1 && raycast->ray_dir_y < 0)
		tex_num = NO;
	return (tex_num);
}

double	get_wall_x(t_man *man, t_raycast *raycast)
{
	double	wall_x;

	if (raycast->side == 0)
		wall_x = man->pos_y+ raycast->perp_wall_dist * raycast->ray_dir_y;
	else
		wall_x = man->pos_x+ raycast->perp_wall_dist * raycast->ray_dir_x;
	wall_x -= floor((wall_x));
	return (wall_x);
}

int	get_texture_x(t_game *game, t_raycast *raycast, double wall_x)
{
	int		tex_x;

	tex_x = (int)(wall_x * (double)game->wall.width);
	if (raycast->side == 0 && raycast->ray_dir_x > 0)
		tex_x = game->wall.width - tex_x - 1;
	if (raycast->side == 1 && raycast->ray_dir_y < 0)
		tex_x = game->wall.width - tex_x - 1;
	return (tex_x);
}

void	put_buffer(t_game *game, t_raycast *raycast, t_texture_info *tex_info, int x)
{
	double			step;
	int				y;
	int				color;

	step = 1.0 * game->wall.height / raycast->line_height;
	tex_info->texPos = (raycast->draw_start - WIN_H / 2 + raycast->line_height / 2) * step;
	y = raycast->draw_start;
	while (y < raycast->draw_end)
	{
		tex_info->tex_y = (int)tex_info->texPos & (game->wall.height - 1);
		tex_info->texPos += step;
		color = game->wall.texture[tex_info->tex_num][game->wall.height * tex_info->tex_y + tex_info->tex_x];
		game->bg.memory[y * WIN_W + x] = color;
		y++;
	}
}

void	select_texture(t_game *game, t_man *man, t_raycast *raycast, int x)
{
	t_texture_info tex_info;
	double	wall_x;
	int		i;

	i = 0;
	wall_x = get_wall_x(man, raycast);
	tex_info.tex_num = get_texture_num(man, raycast);
	tex_info.tex_x = get_texture_x(game, raycast, wall_x);
	put_buffer(game, raycast, &tex_info, x);
}
