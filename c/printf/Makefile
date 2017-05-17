#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 13:33:22 by mriviere          #+#    #+#              #
#    Updated: 2016/10/30 11:44:47 by mriviere         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = ft_oct.c \
		ft_print_d.c \
		ft_printf.c \
		ft_print_c.c \
		ft_print_s.c \
		ft_print_p.c \
		ft_print_su.c \
		ft_print_base.c \
		ft_list.c \
		ft_space_nbr.c \
		ft_if_i_was.c \
		ft_if_i_was2.c

SRCLIBFT =    ft_atoi.c \
    ft_bzero.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_itoa.c \
    ft_lstadd.c \
    ft_lstdel.c \
    ft_lstdelone.c \
    ft_lstiter.c \
    ft_lstmap.c \
    ft_lstnew.c \
    ft_memalloc.c \
    ft_memccpy.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memdel.c \
    ft_memmove.c \
    ft_memset.c \
    ft_putchar.c \
    ft_putchar_fd.c \
    ft_putendl.c \
    ft_putendl_fd.c \
    ft_putnbr.c \
    ft_putnbr_fd.c \
    ft_putstr.c \
    ft_putstr_fd.c \
    ft_strcat.c \
    ft_strchr.c \
    ft_strclr.c \
    ft_strcmp.c \
    ft_strcpy.c \
    ft_strdel.c \
    ft_strdup.c \
    ft_strequ.c \
    ft_striter.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlen.c \
    ft_strmap.c \
    ft_strmapi.c \
    ft_strncat.c \
    ft_strncmp.c \
    ft_strncpy.c \
    ft_strnequ.c \
    ft_strnew.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strsplit.c \
    ft_strstr.c \
    ft_strsub.c \
    ft_strtrim.c \
    ft_tolower.c \
    ft_toupper.c

OBJ = $(SRC:.c=.o)


OBJLIBFT = $(SRCLIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(FLAGS) -c $(addprefix  libft/,$(SRCLIBFT))
		@ar rc $(NAME) $(OBJ) $(OBJLIBFT)
		@ranlib $(NAME)
		@echo "Compilation :\t\t\t\t\t\tCOMP   DONE"
%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS) -I libft/

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJLIBFT)
	@echo ".o deleted : \t\t\t\t\t\tCLEAN  DONE"

fclean: clean
	@rm -f $(NAME)
	@rm -f ./libft/*.o
	@rm -f ./libft/libft.a
	@echo "Folder cleanup : \t\t\t\t\tFCLEAN DONE"

re: fclean all
