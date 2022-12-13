/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwchoi <sunwchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:30:55 by sunwchoi          #+#    #+#             */
/*   Updated: 2022/12/13 13:32:03 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	free_text(t_text *text)
{
	int	i;

	i = -1;
	while (++i < TYPE)
		free(text->element[i]);
	free(text);
}

t_game	*parsing(int ac, char **av)
{
	int		fd;
	t_text	*text;
	t_game	*game;

	if (ac != 2)
		ft_error("argument must be one");
	fd = open_file(av[1]);
	text = read_file(fd);
	game = test_file(text);
	close(fd);
	free_text(text);
	return (game);
}
