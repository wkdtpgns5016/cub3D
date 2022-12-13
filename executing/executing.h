/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwchoi <sunwchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:16:40 by sunwchoi          #+#    #+#             */
/*   Updated: 2022/12/13 14:32:29 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define WIN_W 640
# define WIN_H 360

# define N 0
# define W 1
# define S 2
# define E 3

# include <math.h>
# include "../includes/struct.h"
# include "../minilibx/mlx.h"
# include "../error/error.h"
# include "../parsing/parsing.h"

void	locate_man(t_game *game);
int		key_press(int key_code, t_game *game);
void	raycasting(t_game *game, t_man *man, int width);
void	select_texture(t_game *game, t_man *man, t_raycast *raycast, int x);
void	executing(t_game *game);
void	init_background(t_game *game);
void	paint_background(t_game *game);

#endif
