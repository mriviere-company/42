#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 13:33:22 by mriviere          #+#    #+#              #
#    Updated: 2015/01/24 11:28:39 by mriviere         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_atoi.c \
		ft_memset.c \
		ft_strsplit.c \
		ft_strtrim.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_nbrlen.c \
		ft_pow.c \
		ft_itoa.c \
		ft_getnbr.c \
		ft_strpbrk.c \
		ft_realloc.c \
		ft_putstr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strstr.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_bzero.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strdup.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_iscntrl.c \
		ft_isalpha.c \
		ft_memalloc.c \
		ft_strclr.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_isblank.c \
		ft_isspace.c \
		ft_isgraph.c \
		ft_ispunct.c \
		ft_isxdigit.c \
		ft_ispunct.c \
		ft_putendl.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BIN = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)
	chmod 755 $(NAME)
	@echo "Compilation :\t\t\t\t\t\t\tDONE"

clean :
	/bin/rm -f $(BIN)
	@echo "Object deleted : \t\t\t\t\t\tDONE"

fclean : clean
	/bin/rm -f $(NAME)
	@echo "Folder cleanup : \t\t\t\t\t\tDONE"

re: fclean all
