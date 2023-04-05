NAME = so_long

SRC = \
	so_long.c map_test.c read_map.c check_solvable.c check_map.c\
	handle_keys.c ft_bzero.c locations.c move_escape.c check_for_solved.c \
	ft_printf_main.c  ft_intdigit.c ft_inthex.c ft_intitoa.c \
	ft_intptr.c ft_intputchar.c ft_intstr.c ft_intstrlen.c \
	ft_intutoa.c  ft_intudigits.c\

OFILES = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	cc $(FLAGS) $(OFILES) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean: 
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

%.o: %.c
	cc $(FLAGS) -c -o $@ $^

re: fclean all
