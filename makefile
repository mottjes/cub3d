NAME = cub3d

SRC = 	src/main.c					\

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

MLX_PATH = minilibx-linux

MLX_NAME = libmlx.a

MLX = $(MLX_PATH) $(MLX_NAME)

MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

%.o: %.cub3d
	$(CC) $(CFLAGS) -I./minilibx-linux -c - o $@ $<