/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:41:54 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/11 21:30:55 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_stack {
	long			nbr;
	long			sorted;
	long			fixed;
	struct s_stack	*next;
}	t_stack;

typedef struct s_instructions {
	char			*solution;
}	t_instructions;


int			ft_printf(const char *mains, ...);
int			ft_isalpha(int a);
int			ft_isdigit(int a);
int			ft_isalnum(int a);
int			ft_isascii(int a);
int			ft_isprint(int a);
size_t		ft_strlen(const char *string);
void		*ft_memset(void *a, int b, size_t c);
void		ft_bzero(void *a, size_t b);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsizei);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi(const char *str);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_printf(const char *mains, ...);
int			ft_intputchar(int character, int count);
int			ft_intstr(char *src, int count);
int			ft_intptr(unsigned long long pointer, int count);
int			ft_inthex(unsigned long long num, int count, int instruction);
int			ft_checker(va_list args, const char tag, int count);
int			ft_intitoa(int a, int count);
int			ft_intutoa(unsigned int a, int count);
size_t		ft_intstrlen(const char *string);
int			ft_intdigits(int number);
int			ft_intudigits(unsigned int number);

//Currently used in Push_Swap
char			**ft_split(char const *s, char c);
int				add_to_stack(t_stack **head, const char *str);
t_stack			*create_empty(t_stack **item);
long long		ft_atou(const char *str);
int 			ft_error_free(t_stack **stack_a, char **split);
void 			free_stack(t_stack **stack);
int				sort_the_stack(t_stack **stack_a);
short 			find_next_smallest(t_stack **stack_a, long j);
char			*ft_ltoa(long n);
void 			assignfixed(t_stack **stack);
int 			incriment(t_instructions **to_increase, int stacksize);
int				math_check(t_instructions **solved, long fixed, long sorted, long stack_size);
int				checks_out(t_stack **stack_a, t_instructions **solution, int size);
t_instructions *bruteforce(t_stack **stack_a, int i, t_instructions **solution);
int 			calculatenext(t_instructions **string, int index, int stacksize);

#endif