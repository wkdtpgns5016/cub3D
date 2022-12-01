#ifndef EXECUTING_H
# define EXECUTING_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

#define KEY_LEFT 123
#define KEY_RIGHT 124

#define WIN_W 1920
#define WIN_H 1080

#define STEP 1
#define TURN 10

#include "../includes/struct.h"

#include "../minilibx/mlx.h"
#include "../error/error.h"
void	locate_man(t_game *game);
int	key_press(int key_code, t_game *game);

#endif
