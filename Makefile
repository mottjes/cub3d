NAME = cub3d

SRC = 	src/main.c					\
		src/exit.c					\
		src/key_hook.c				\
		src/init.c					\
		src/render.c				\
		src/calculations.c			\
		src/texture.c   			\

CC = gcc

CFLAGS = #-Wall -Wextra -Werror -no-pie

OBJ = $(SRC:.c=.o)

MLX_PATH = ./minilibx-linux

MLX_NAME = libmlx.a

MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -I./minilibx-linux -c -o $@ $<

clean:
	rm -f $(OBJ)
	make -C $(MLX_PATH) clean
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re