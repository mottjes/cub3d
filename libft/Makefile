# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 11:39:18 by mottjes           #+#    #+#              #
#    Updated: 2024/02/29 15:14:39 by mottjes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	./ft_atoi.c				\
		./ft_bzero.c			\
		./ft_calloc.c			\
		./ft_isalnum.c			\
		./ft_isalpha.c			\
		./ft_isascii.c			\
		./ft_isdigit.c			\
		./ft_isprint.c			\
		./ft_itoa.c				\
		./ft_memchr.c			\
		./ft_memcmp.c			\
		./ft_memcpy.c			\
		./ft_memmove.c			\
		./ft_memset.c			\
		./ft_putchar_fd.c		\
		./ft_putendl_fd.c		\
		./ft_putnbr_fd.c		\
		./ft_putstr_fd.c		\
		./ft_split.c			\
		./ft_strchr.c			\
		./ft_strdup.c			\
		./ft_striteri.c			\
		./ft_strjoin.c			\
		./ft_strlcat.c			\
		./ft_strlcpy.c			\
		./ft_strlen.c			\
		./ft_strmapi.c			\
		./ft_strncmp.c			\
		./ft_strnstr.c			\
		./ft_strrchr.c			\
		./ft_strtrim.c			\
		./ft_substr.c			\
		./ft_tolower.c			\
		./ft_toupper.c			\
		./get_next_line.c 		\
		./get_next_line_utils.c	\
		
B_SRC =	./ft_lstclear.c			\
		./ft_lstdelone.c		\
		./ft_lstiter.c			\
		./ft_lstlast.c			\
		./ft_lstnew.c			\
		./ft_lstsize.c			\
		./ft_lstadd_front.c		\
		./ft_lstadd_back.c		\
		./ft_lstmap.c			\
		
OBJS = $(SRC:.c=.o)

B_OBJS = $(B_SRC:.c=.o)

HDR = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus:  $(B_OBJS) $(OBJS)
	@ar rc $(NAME) $(B_OBJS) $(OBJS)
	@ranlib $(NAME)

$(OBJS):
	@cc -Wall -Wextra -Werror -c $(HDR) $(SRC)

$(B_OBJS):
	@cc -Wall -Wextra -Werror -c $(HDR) $(B_SRC)

clean:
	@rm -f $(OBJS) $(B_OBJS) $(HDR).gch

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re