CC = cc -Wall -Wextra -Werror 
RSCS = parsing/parsing.c \
	   parsing/open_file.c \
	   parsing/read_element.c \
	   parsing/read_map.c \
	   parsing/read_file.c \
	   parsing/test_map.c \
	   parsing/test_file.c \
	   error/error.c \
	   executing/executing.c \
	   executing/locate_man.c\
	   executing/key.c \
	   executing/raycasting.c\
	   executing/select_texture.c\
	   main.c
OBJS = $(RSCS:%.c=%.o)
NAME = cub3d

$(NAME): $(OBJS)
	$(MAKE) -C ./libft bonus
	$(MAKE) -C ./minilibx
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -lz -Llibft -Lminilibx -lft -o $(NAME) -lncurses

all : $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./minilibx clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./minilibx fclean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY = all clean fclean re bonus
