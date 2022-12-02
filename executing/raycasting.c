#include "../includes/struct.h"
#include <math.h>

void	init_raycast2(t_raycast *raycast, t_info *info)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (info->pos_x - raycast->map_x) * raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = \
		(raycast->map_x + 1.0 - info->pos_x) * raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (info->pos_y - raycast->map_y) * raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = \
		(raycast->map_y + 1.0 - info->pos_y) * raycast->delta_dist_y;
	}
}

void	init_raycast(t_raycast *raycast, t_info *info, int x, int width)
{
	raycast->camera_x = 2 * x / (double)width - 1;
	raycast->ray_dir_x = info->dir_x + info->plane_x * raycast->camera_x;
	raycast->ray_dir_y = info->dir_y + info->plane_y * raycast->camera_x;
	raycast->map_x = (int)info->pos_x;
	raycast->map_y = (int)info->pos_y;
	raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	init_raycast2(raycast, info);
}

void	dda_algorithm(t_game *game, t_info *info, t_raycast *raycast)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			side = 1;
		}
		if (game->map[raycast->map_y][raycast->map_x] > 0)
			hit = 1;
	}
}

void	raycasting(t_game *game, t_info *info, int width)
{
	int			x;
	double	preDist;
	t_raycast	raycast;

	x = 0;
	while (x < width)
	{
		
		init_raycast(&raycast, info, x, width);
		dda_algorithm(game, info, &raycast);
		
		//preDist = raycast.perpWallDist;
	}
}
