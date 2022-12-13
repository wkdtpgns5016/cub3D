/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwchoi <sunwchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:11:30 by sunwchoi          #+#    #+#             */
/*   Updated: 2022/12/13 14:11:35 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"
#include "../includes/struct.h"

void	init_raycast2(t_raycast *raycast, t_man *man)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (man->pos_x - raycast->map_x) \
								* raycast->delta_dist_x;
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
		raycast->side_dist_y = (man->pos_y - raycast->map_y) \
								* raycast->delta_dist_y;
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
	raycast->delta_dist_x = sqrt(1 + (raycast->ray_dir_y * raycast->ray_dir_y) \
			/ (raycast->ray_dir_x * raycast->ray_dir_x));
	raycast->delta_dist_y = sqrt(1 + (raycast->ray_dir_x * raycast->ray_dir_x) \
		/ (raycast->ray_dir_y * raycast->ray_dir_y));
	init_raycast2(raycast, man);
}

void	calc_distance(int side, t_raycast *raycast, t_man *man, int height)
{
	if (side == 0)
		raycast->perp_wall_dist = \
		(raycast->map_x - man->pos_x + (1.0 - raycast->step_x) / 2) \
		/ raycast->ray_dir_x;
	else
		raycast->perp_wall_dist = \
		(raycast->map_y - man->pos_y + (1.0 - raycast->step_y) / 2) \
		/ raycast->ray_dir_y;
	raycast->line_height = (int)((double)height / raycast->perp_wall_dist);
	raycast->draw_start = -raycast->line_height / 2 + WIN_H / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + WIN_H / 2;
	if (raycast->draw_end >= WIN_H)
		raycast->draw_end = WIN_H - 1;
}

void	dda_algorithm(t_game *game, t_man *man, t_raycast *raycast)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (game->map[raycast->map_y][raycast->map_x] > '0')
			hit = 1;
	}
	calc_distance(raycast->side, raycast, man, WIN_H);
}

void	raycasting(t_game *game, t_man *man, int width)
{
	int			x;
	t_raycast	raycast;

	x = 0;
	while (x < width)
	{
		init_raycast(&raycast, man, x, width);
		dda_algorithm(game, man, &raycast);
		select_texture(game, man, &raycast, x);
		x++;
	}
}
