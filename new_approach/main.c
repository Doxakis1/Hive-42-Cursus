/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:37:44 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/14 19:50:22 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_push_swap.h"

int	main(int argc, char const **argv)
{
	int				i;
	char			**a;
	t_instructions	*solution;
	t_stack			*stack_a;

	a = NULL;
	stack_a = NULL;
	solution = malloc(sizeof(t_instructions));
	i = 1;
	if (argc >= 2 && solution)
	{
		solution->solution = NULL;
		if (argc == 2)
			if (!(make_from_one_string(a, argv[1], &stack_a)))
				return (ft_error_free(&stack_a, a));
		while (i < argc && argc > 2)
		{
			if (!(add_to_stack(&stack_a, argv[i++])))
				return (ft_error_free(&stack_a, a));
		}
		i = sort_the_stack(&stack_a);
		if (!i)
			return (ft_error_free(&stack_a, a));
		if (i <= 7)
			solution = bruteforce(&stack_a, i, &solution);
		if (solution->solution != NULL)
			print_solution(solution->solution);
	}
	return (0);
}
