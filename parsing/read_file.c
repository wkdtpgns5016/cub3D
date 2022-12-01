#include "parsing.h"
#include <stdlib.h>

int is_empty_line(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\n' || *line == 0)
		return (1);
	return (0);
}

char *jump_empty_line(int fd)
{
	char *ret;

	ret = get_next_line(fd);
	if (!ret)
		ft_error("map is wrong");
	while (is_empty_line(ret))
	{
		free(ret);
		ret = get_next_line(fd);
		if (!ret)
			ft_error("map is wrong");
	}
	return (ret);
}

void read_map(int fd, t_text *text)
{
	char *join;
	char *tmp1;
	char *tmp2;

	tmp1 = jump_empty_line(fd);
	tmp2 = get_next_line(fd);
	while (tmp2 && !is_empty_line(tmp2))
	{
		join = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
		tmp1 = join;
		tmp2 = get_next_line(fd);
	}
	if (tmp2)
		ft_error("map is wrong");
	text->map = ft_split(join, '\n');
	free(join);
}

t_text *read_file(int fd)
{
	t_text *text;

	text = (t_text *)malloc(sizeof(t_text));
	read_element(fd, text);
/*
	int i = 0;
	while (i < TYPE)
		printf("%s\n", text->element[i++]);
*/
	read_map(fd, text);
/*
	i = 0;
	while (text->map[i])
		printf("%s\n", text->map[i++]);
*/
	return (text);
}
