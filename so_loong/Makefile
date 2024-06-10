# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salaoui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 12:13:18 by salaoui           #+#    #+#              #
#    Updated: 2024/04/21 12:13:21 by salaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c map_dimentions.c is_the_map_valid.c move_player.c get_next_line.c get_next_line_utils.c moving_ft.c error.c check_winning.c
LIBRARIES = libmlx.a libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework Appkit
NAME = so_long

SRC_o := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_o)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_o) $(LIBRARIES) $(MLXFLAGS)

clean:
	rm -f $(SRC_o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(SRC_o)
