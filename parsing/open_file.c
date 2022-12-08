#include "parsing.h"

static void	check_filename(char *file)
{
	char *extension;

	extension = ft_strrchr(file, '.');
	if (!extension)
		ft_error("file extension must be .cub");
	if (ft_strncmp(".cub", extension, 5))
		ft_error("file extension must be .cub");
}

int open_file(char *file)
{
	int fd;

	check_filename(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("file open is failed");
	return (fd);
}
