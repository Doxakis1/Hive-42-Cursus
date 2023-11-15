NAME = megaphone

SRC = Megaphone.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean: 
	rm -f $(NAME)
fclean: 
	make clean

re: fclean all
