NAME = PhoneBook

SRC = main.cpp PhoneBook.cpp Contact.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean: 
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
