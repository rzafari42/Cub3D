# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzafari <rzafari@student.42.fr>              +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/14 13:25:21 by rzafari            #+#    #+#             #
#    Updated: 2020/05/04 16:55:22 by rzafari42        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.out
HEADER= cub3d.h get_next_line.h
CC = gcc
MLXFLAGS = -L/usr/local/lib -lmlx -lm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lbsd
CCFLAGS = -Wall -Wextra -Werror
SRC = cub3d_sprites.c parse_initialization.c ft_savebmp.c catching_keys.c\
	ceilfloor.c game_modes.c initializations00.c initializations01.c copy_map.c\
	key_to_functions.c move00.c move01.c parsing.c parsingtwo.c parsingthree.c\
	raycasting.c raycastingtwo.c sprites.c spritestwo.c path.c pathtwo.c textures.c\
	resolution.c utils.c utilstwo.c utilsthree.c utilsfour.c check_map.c check_maptwo.c\
	color.c mapfillspace.c get_next_line.c get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CCFLAGS) $(OBJ) $(MLXFLAGS) -fsanitize=address -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
