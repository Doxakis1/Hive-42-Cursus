/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:41:54 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 05:21:24 by mkaratzi         ###   ########.fr       */
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
	char			*str;
	struct s_stack	*next;
}	t_stack;

typedef struct s_instructions {
	char			*solution;
}	t_instructions;

//Currently used in Push_Swap

char			**ft_split(char const *s, char c);
int				add_to_stack(t_stack **head, const char *str);
t_stack			*create_empty(t_stack **item);
long			ft_atou(const char *str);
int				ft_error_free(t_stack **stack_a, char **split);
void			free_stack(t_stack **stack);
int				sort_the_stack(t_stack **stack_a);
short			find_next_smallest(t_stack **stack_a, long j);
char			*ft_ltoa(long n);
void			assignfixed(t_stack **stack, int size);
int				make_from_one_string(char **str, const char *given,
					t_stack **head);
char			*make_into_str(long n, int size);
int				fixed_size(int size);
int				ft_printf(const char *mains, ...);
size_t			ft_strlen(const char *s);
t_instructions	*bruteforce(t_stack **stack_a, int stacksize,
					t_instructions **solution);
// Bruteforce utils
int				new_incriment(t_instructions **sol, int size);
int				calculatenext(t_instructions **string, int index, int size);
int				checks_out(t_stack **stack_a, t_instructions **solution,
					int size);
int				math_check(t_instructions **sol, long fixed, long sorted,
					long stack_size);
int				calculate_stacksize(char *instructions, int size, int index,
					int a);
long			check_move_for_a(int a_st, int b_st, int fixed, int move);
long			check_move_for_b(int a_st, int b_st, int fixed, int move);

//smart solution
t_instructions	*smart_solution(t_stack **stack_a, int size,
					t_instructions **sol);

// printing
int				print_solution(char *solution);

#endif