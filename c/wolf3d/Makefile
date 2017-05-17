#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 11:48:02 by mriviere          #+#    #+#              #
#    Updated: 2016/05/04 17:15:12 by mriviere         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Wolf3d

SRC = main.c tools.c draw.c keys.c image.c cam.c map.c init.c

LIB = ./libft/libft.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

INC = -I./libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ)
	@make -C ./libft
	@make -C ./minilibx_macos
	@gcc -o $(NAME) $(OBJ) $(LIB) $(INC)
	@echo "Compilation :\t\t\t\t\t\tCOMP   DONE"

%.o: %.c
	@gcc -Wall -Wextra -Werror -O3 -c -g $< $(INC)

clean:
	@make -C ./libft clean
	@rm -f $(OBJ)
	@echo ".o deleted : \t\t\t\t\t\tCLEAN  DONE"

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)
	@echo "Folder cleanup : \t\t\t\t\tFCLEAN DONE"

re: fclean all