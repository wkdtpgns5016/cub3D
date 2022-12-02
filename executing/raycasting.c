#include "../includes/struct.h"
#include <math.h>

void	init_raycast2(t_raycast *raycast, t_man *man)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (man->pos_x - raycast->map_x) * raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = \
		(raycast->map_x + 1.0 - man->pos_x) * raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (man->pos_y - raycast->map_y) * raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = \
		(raycast->map_y + 1.0 - man->pos_y) * raycast->delta_dist_y;
	}
}

void	init_raycast(t_raycast *raycast, t_man *man, int x, int width)
{
	raycast->camera_x = 2 * x / (double)width - 1;
	raycast->ray_dir_x = man->dir_x + man->plane_x * raycast->camera_x;
	raycast->ray_dir_y = man->dir_y + man->plane_y * raycast->camera_x;
	raycast->map_x = (int)man->pos_x;
	raycast->map_y = (int)man->pos_y;
	raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	init_raycast2(raycast, man);
}

void	dda_algorithm(t_game *game, t_man *man, t_raycast *raycast)
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

void	raycasting(t_game *game, t_man *man, int width)
{
	int			x;
	double	preDist;
	t_raycast	raycast;

	x = 0;
	while (x < width)
	{
		
		init_raycast(&raycast, man, x, width);
		dda_algorithm(game, man, &raycast);
		
		//preDist = raycast.perpWallDist;
	}
}
