# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzafari <rzafari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/14 13:25:21 by rzafari            #+#    #+#              #
#    Updated: 2020/04/14 13:25:21 by rzafari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a
HEADER= cub3d.h get_next_line.h
CC = cc
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
CCFLAGS = -Wall -Wextra -Werror -I$(HEADER)
SRC = cub3d_sprites.c catching_keys.c Ceil_Floor.c game_modes.c initializations00.c\
		initializations01.c key_to_functions.c move00.c move01.c parsing.c\
		raycasting.c sprites.c textures.c utils.c get_next_line.c \
		get_next_line_utils.c
LIB = libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(MLXFLAGS) $(CCFLAGS) -L./libft -lft -c $(OBJ)


$(LIB):
	make -C libft re

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean:
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY : all clean fclean re