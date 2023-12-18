NAME = exec_ex02

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all fclean re

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)
re: fclean all