#ifndef CUB3D_H
# define CUB3D_H

#include "struct.h"
#include "../executing/executing.h"

t_game	*parsing(int ac, char **av);
void	executing(t_game *game);

#endif
