#include "../includes/struct.h"
#include "./raycasting.h"
#include <math.h>

void	init_raycast2(t_raycast *raycast, t_info *info)
{
	if (raycast->rayDirX < 0)
	{
		raycast->stepX = -1;
		raycast->sideDistX = (info->posX - raycast->mapX) * raycast->deltaDistX;
	}
	else
	{
		raycast->stepX = 1;
		raycast->sideDistX = \
		(raycast->mapX + 1.0 - info->posX) * raycast->deltaDistX;
	}
	if (raycast->rayDirY < 0)
	{
		raycast->stepY = -1;
		raycast->sideDistY = (info->posY - raycast->mapY) * raycast->deltaDistY;
	}
	else
	{
		raycast->stepY = 1;
		raycast->sideDistY = \
		(raycast->mapY + 1.0 - info->posY) * raycast->deltaDistY;
	}
}

void	init_raycast(t_raycast *raycast, t_info *info, int x, int width)
{
	raycast->cameraX = 2 * x / (double)width - 1;
	raycast->rayDirX = info->dirX + info->planeX * raycast->cameraX;
	raycast->rayDirY = info->dirY + info->planeY * raycast->cameraX;
	raycast->mapX = (int)info->posX;
	raycast->mapY = (int)info->posY;
	raycast->deltaDistX = fabs(1 / raycast->rayDirX);
	raycast->deltaDistY = fabs(1 / raycast->rayDirY);
	init_raycast2(raycast, info);
}

void	dda_algorithm(t_game *game, t_info *info, t_raycast *raycast)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->sideDistX < raycast->sideDistY)
		{
			raycast->sideDistX += raycast->deltaDistX;
			raycast->mapX += raycast->stepX;
			side = 0;
		}
		else
		{
			raycast->sideDistY += raycast->deltaDistY;
			raycast->mapY += raycast->stepY;
			side = 1;
		}
		if (game->map[raycast->mapY][raycast->mapX] > 0)
			hit = 1;
	}
}

void	raycasting(t_game *game, t_info *info, int width)
{
	int			x;
	t_raycast	raycast;

	x = 0;
	while (x < width)
	{
		init_raycast(&raycast, info, x, width);
		dda_algorithm(game, info, &raycast);
	}
}
