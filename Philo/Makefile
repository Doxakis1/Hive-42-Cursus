# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 19:03:31 by mkaratzi          #+#    #+#              #
#    Updated: 2023/09/05 18:49:56 by mkaratzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
COMPILE_FLAGS = -Wall -Wextra -Werror -Ofast
SRC = \
	ft_atou_to_dest.c print_errors.c check_invalid_arguments.c get_time.c \
	initialize_monitor.c initialize_print_states.c initialize_philo_threads.c\
	initialize_forks.c initialize_philos.c simulation.c philo_loop.c main.c \
	philo_loop_helpers.c \

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
