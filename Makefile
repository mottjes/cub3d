NAME = cub3d

SRC = 	src/main.c					\
		src/exit.c					\
		src/key_hook.c				\
		src/init.c					\
		src/render.c				\
		src/calculations.c			\
		src/minimap.c				\
		src/texture.c   			\

CC = gcc

CFLAGS = #-Wall -Wextra -Werror -no-pie

OBJ = $(SRC:.c=.o)

MLX_PATH = ./minilibx-linux

LIBFT_PATH = ./libft

MLX_NAME = libmlx.a

MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

all: $(NAME) $(OBJ) $(LIBFT)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_PATH)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT_PATH)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -I./minilibx-linux -c -o $@ $<

clean:
	rm -f $(OBJ)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re