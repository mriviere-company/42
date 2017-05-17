#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 16:35:36 by mriviere          #+#    #+#              #
#    Updated: 2016/10/02 10:50:12 by mriviere         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = main.c ft_mandelbrot.c ft_julia.c place_it.c ft_burning_ship.c key.c dir.c mouse.c start.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

HD = fractol.h

INC = -I./libft/

all: $(NAME)

$(NAME): libft $(OBJ)
	make -C ./libft
	make -C ./minilibx_macos
	gcc -o $(NAME) $(OBJ) $(LIB) $(INC)

%.o: %.c $(HD)
	gcc -Wall -Wextra -Werror -O3 -c $< $(INC)

clean:
	make -C ./libft clean
	make -C ./minilibx_macos clean
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
