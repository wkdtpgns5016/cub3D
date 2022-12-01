#ifndef PARSING_H
# define PARSING_H

#define SUCCESS 0
#define FAIL 1

#define EA 0
#define WE 1
#define SO 2
#define NO 3
#define C 4
#define F 5

#define TEXTURE 0
#define COLOR 4
#define TYPE 6

#define WALL '1'
#define FLOOR '0'

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/struct.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"


int ft_error(char *message);
int	open_file(char *file);
void	read_element(int fd, t_text *text);
t_text	*read_file(int fd);
void	test_map(char **map, t_game *game);
t_game	*test_file(t_text *text);
t_game	*parsing(int ac, char **av);

#endif
