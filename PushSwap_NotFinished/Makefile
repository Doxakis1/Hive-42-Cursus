# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 19:03:31 by mkaratzi          #+#    #+#              #
#    Updated: 2022/12/08 11:02:11 by mkaratzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_pushswap.a
COMPILE_FLAGS = -c -Wall -Wextra -Werror
SRC = \
	ft_printf/ft_printf_main.c  ft_printf/ft_intdigit.c ft_printf/ft_inthex.c ft_printf/ft_intitoa.c \
	ft_printf/ft_intptr.c ft_printf/ft_intputchar.c ft_printf/ft_intstr.c ft_printf/ft_intstrlen.c \
	ft_printf/ft_intutoa.c  ft_printf/ft_intudigits.c \
	libft/ft_split.c \
	ft_atou.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC:.c=.o) compile
	ar rcs $(NAME) ft_printf_main.o  ft_intdigit.o ft_inthex.o ft_intitoa.o \
	ft_intptr.o ft_intputchar.o ft_intstr.o ft_intstrlen.o \
	ft_intutoa.o  ft_intudigits.o ft_split.o  \
	
$(SRC:.c=.o): $(SRC)
	cc $(COMPILE_FLAGS) $(SRC)

compile: $(NAME) $(SRC:.c=.o)
	gcc ft_pushswap.c $(SRC) -o push_swap && make clean

clean:
	rm -f ft_printf_main.o  ft_intdigit.o ft_inthex.o ft_intitoa.o \
	ft_intptr.o ft_intputchar.o ft_intstr.o ft_intstrlen.o \
	ft_intutoa.o  ft_intudigits.o ft_split.o ft_pushswap.o ft_atou.o \

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

controlled: compile clean