NAME = megaphone

SRC = Megaphone.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean: 
	rm -f $(NAME)
fclean: clean
	rm -f $(NAME)

re: fclean all
