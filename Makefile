# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzafari <rzafari@student.42.fr>              +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/14 13:25:21 by rzafari            #+#    #+#             #
#    Updated: 2020/04/14 13:25:21 by rzafari           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a
HEADER= cub3d.h get_next_line.h
CC = cc
MLXFLAGS = -L/usr/local/lib -lmlx -lm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lbsd
CCFLAGS = -Wall -Wextra -Werror
SRC = cub3d_sprites.c ft_savebmp.c catching_keys.c ceilfloor.c game_modes.c\
	initializations00.c initializations01.c key_to_functions.c move00.c move01.c\
	parsing.c raycasting.c sprites.c spritestwo.c textures.c utils.c utilstwo.c\
	utilsthree.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(SRC)
	$(CC) -o $(NAME) $(MLXFLAGS) $(CCFLAGS) -c $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
