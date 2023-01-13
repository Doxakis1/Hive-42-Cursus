# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 19:03:31 by mkaratzi          #+#    #+#              #
#    Updated: 2022/11/23 19:34:12 by mkaratzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
COMPILE_FLAGS = -c -Wall -Wextra -Werror
SRC = \
	ft_printf_main.c  ft_intdigit.c ft_inthex.c ft_intitoa.c \
	ft_intptr.c ft_intputchar.c ft_intstr.c ft_intstrlen.c \
	ft_intutoa.c  ft_intudigits.c\

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	ar rcs $(NAME) $(SRC:.c=.o)

$(SRC:.c=.o): $(SRC)
	cc $(COMPILE_FLAGS) $(SRC)

clean:
	rm -f $(SRC:.c=.o) 

fclean: clean
	rm -f $(NAME)

re: fclean all
