#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 11:48:02 by mriviere          #+#    #+#              #
#    Updated: 2016/10/20 16:05:15 by mriviere         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = main.c get_next_line.c tools.c bresenham.c parse.c matrice.c

LIB = ./libft/libft.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

INC = -I./libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ)
	make -C ./libft
	make -C ./minilibx_macos
	gcc -o $(NAME) $(OBJ) $(LIB) $(INC)

%.o: %.c
	gcc -Wall -Wextra -Werror -O3 -c -g $< $(INC)

clean:
	make -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
