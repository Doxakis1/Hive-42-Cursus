# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 19:03:31 by mkaratzi          #+#    #+#              #
#    Updated: 2023/08/26 05:27:25 by mkaratzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
COMPILE_FLAGS = -Wall -Wextra -Werror
SRC = \
	check_invalid_arguments.c initialize_simulation.c main.c philo.c print_errors.c  utils.c\

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	cc $(COMPILE_FLAGS) -lpthread -o $(NAME) $(SRC:.c=.o)

$(SRC:.c=.o): $(SRC)
	cc -c $(COMPILE_FLAGS) $(SRC)

clean:
	rm -f $(SRC:.c=.o) 

fclean: clean
	rm -f $(NAME)

re: fclean all
