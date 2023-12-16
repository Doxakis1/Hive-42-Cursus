NAME = exec_ex05

SRC = main.cpp  Harl.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all fclean re

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)
re: fclean all