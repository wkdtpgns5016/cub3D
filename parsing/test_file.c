#include "parsing.h"

static int	ft_atoRGB(char *element)
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
	int dummy;

	i = -1;
	while (++i < COLOR)
	{
		game->img_ptr[i] = mlx_xpm_file_to_image\
						   (game->mlx_ptr, element[i], &dummy, &dummy);
		if (!game->img_ptr[i])
			ft_error("image path is invalid");
	}
	i = COLOR - 1;
	while (++i < TYPE)
		game->color[i - COLOR] = ft_atoRGB(element[i]);
}

t_game	*test_file(t_text *text)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->mlx_ptr = mlx_init();
	test_element(text->element, game);
	

//	printf("%d %d\n", game->color[0], game->color[1]);
	test_map(text->map, game);
	return (game);
}
