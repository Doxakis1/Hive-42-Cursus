
COMPILE_FLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

compile:
	gcc *.c ft_printf/*.c libft/*.c -o push_swap && make clean

clean:
	rm -f *.o

fclean: clean
	rm -f

re: fclean all

controlled: compile clean