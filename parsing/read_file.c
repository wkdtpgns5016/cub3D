#include "parsing.h"

t_text *read_file(int fd)
{
	t_text *text;

	text = (t_text *)malloc(sizeof(t_text));
	read_element(fd, text);
	text->map = read_map(fd);
	return (text);
}
