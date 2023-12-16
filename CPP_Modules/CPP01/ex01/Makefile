NAME = exec_ex01

SRC = main.cpp Zombie.cpp zombieHorde.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all fclean re

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)
re: fclean all