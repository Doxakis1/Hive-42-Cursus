# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 19:03:31 by mkaratzi          #+#    #+#              #
#    Updated: 2023/02/21 16:25:54 by mkaratzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
COMPILE_FLAGS = -Wall -Wextra -Werror
SERVER_SRC = \
	ft_printf_main.c  ft_intdigit.c ft_inthex.c ft_intitoa.c \
	ft_intptr.c ft_intputchar.c ft_intstr.c ft_intstrlen.c \
	ft_intutoa.c  ft_intudigits.c	server.c\

CLIENT_NAME = client
COMPILE_FLAGS = -Wall -Wextra -Werror
CLIENT_SRC = \
	ft_printf_main.c  ft_intdigit.c ft_inthex.c ft_intitoa.c \
	ft_intptr.c ft_intputchar.c ft_intstr.c ft_intstrlen.c \
	ft_intutoa.c  ft_intudigits.c	client.c\

.PHONY: all clean fclean re

all: $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(CLIENT_SRC:.c=.o)
	gcc  -o $(CLIENT_NAME) $(CLIENT_SRC:.c=.o)

$(CLIENT_SRC:.c=.o): $(SERVER_SRC)
	gcc  -c $(COMPILE_FLAGS) $(CLIENT_SRC)

$(SERVER_NAME): $(SERVER_SRC:.c=.o)
	gcc  -o $(SERVER_NAME) $(SERVER_SRC:.c=.o)

$(SERVER_SRC:.c=.o): $(SERVER_SRC)
	gcc  -c $(COMPILE_FLAGS) $(SERVER_SRC)

clean:
	rm -f $(SERVER_SRC:.c=.o) 

fclean: clean
	rm -f $(SERVER_NAME)

re: fclean all
