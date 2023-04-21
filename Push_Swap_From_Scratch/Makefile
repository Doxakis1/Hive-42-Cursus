NAME = push_swap

SRC = \
bruteforce.c bruteforce_utils.c ft_atou.c ft_ltoa.c main.c \
make_the_stack.c math_check.c print_solution.c big_sort.c \
sort_the_stack.c the_moves.c \
libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c  \
libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c  \
libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c \
libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c \
libft/ft_lstiter_bonus.c libft/ft_lstlast_bonus.c \
libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c \
libft/ft_lstsize_bonus.c libft/ft_memchr.c libft/ft_memcmp.c \
libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c \
libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c \
libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c \
libft/ft_tolower.c libft/ft_toupper.c \
ft_printf/ft_intdigit.c ft_printf/ft_inthex.c  ft_printf/ft_intitoa.c \
ft_printf/ft_intptr.c ft_printf/ft_intputchar.c ft_printf/ft_intstr.c \
ft_printf/ft_intstrlen.c ft_printf/ft_intudigits.c \
ft_printf/ft_intutoa.c ft_printf/ft_printf_main.c \
\

OFILES = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	cc $(FLAGS) $(OFILES) -o $(NAME)

clean: 
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

%.o: %.c
	cc $(FLAGS) -c -o $@ $^

re: fclean all
