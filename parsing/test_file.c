/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwchoi <sunwchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:43:51 by sunwchoi          #+#    #+#             */
/*   Updated: 2022/12/13 13:43:53 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../executing/executing.h"

static int	ft_atorgb(char *element)
{
	int	rgb;
	int	i;
	int	num;

	rgb = 0;
	i = 0;
	while (++i < 4)
	{
		num = 0;
		if (!('0' <= *element && *element <= '9'))
			ft_error("color is invalid");
		while ('0' <= *element && *element <= '9')
		{
			num = (num * 10) + (*element - '0');
			if (num > 255)
				ft_error("color is invalid");
			element++;
		}
		if (*element == ',')
			element++;
		rgb = rgb << 8 | num;
	}
	return (rgb);
}

void	test_element(char **element, t_game *game)
{
	int	i;

	i = -1;
	game->mlx_ptr = mlx_init();
	while (++i < COLOR)
	{
		game->wall.img_ptr[i] = mlx_xpm_file_to_image(game->mlx_ptr, \
													element[i], \
													&game->wall.width, \
													&game->wall.height);
		if (!game->wall.img_ptr[i])
			ft_error("image path is invalid");
		game->wall.texture[i] = (int *)mlx_get_data_addr(game->wall.img_ptr[i], \
									&game->wall.bytes_per_pixel, \
									&game->wall.size_line, &game->wall.endian);
	}
	i = COLOR - 1;
	while (++i < TYPE)
		game->color[i - COLOR] = ft_atorgb(element[i]);
}

t_game	*test_file(t_text *text)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	test_map(text->map, game);
	test_element(text->element, game);
	return (game);
}
