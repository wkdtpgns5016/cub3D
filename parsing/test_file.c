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

int	*get_texture(t_game *game, int idx)
{
	// texture 생성함수임
	
}

// 이거 참조
// void	init_background(t_game *game)
// {
// 	t_bg	bg;
// 	int	bits_per_byte;
// 	int	bits_per_pixel;

// 	bits_per_byte = 8;
// 	bg.img_ptr = mlx_new_image(game->mlx_ptr, WIN_W, WIN_H);
// 	bg.img_memory = mlx_get_data_addr(bg.img_ptr, &bits_per_pixel, \
// 		&bg.size_line, &bg.endian);
// 	bg.bytes_per_pixel = bits_per_pixel / bits_per_byte;
// 	bg.horizon = WIN_H / (2 * bg.bytes_per_pixel);
// 	game->bg = bg;
// }

void	test_element(char **element, t_game *game)
{
	int	i;
	int dummy;

	i = -1;
	while (++i < COLOR)
	{
		game->wall.img_ptr[i] = mlx_xpm_file_to_image\
						   (game->mlx_ptr, element[i], \
						   &game->wall.width, &game->wall.height);
		// 여따가 텍스처 생성
		if (!game->wall.img_ptr[i])
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
