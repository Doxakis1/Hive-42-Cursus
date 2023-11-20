NAME = PhoneBook

SRC = *.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean: 
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
