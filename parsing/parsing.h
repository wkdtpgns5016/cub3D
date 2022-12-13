/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwchoi <sunwchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:50:11 by sunwchoi          #+#    #+#             */
/*   Updated: 2022/12/13 13:50:12 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../includes/struct.h"
# include "../libft/libft.h"
# include "../error/error.h"
# include "../minilibx/mlx.h"

# define SUCCESS 0
# define FAIL 1
# define EA 0
# define WE 1
# define SO 2
# define NO 3
# define C 4
# define F 5
# define TEXTURE 0
# define COLOR 4
# define TYPE 6
# define WALL '1'
# define FLOOR '0'

int		open_file(char *file);
void	read_element(int fd, t_text *text);
char	**read_map(int fd);
t_text	*read_file(int fd);
void	test_map(char **map, t_game *game);
t_game	*test_file(t_text *text);
t_game	*parsing(int ac, char **av);

#endif
