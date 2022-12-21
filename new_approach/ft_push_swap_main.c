/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:37:44 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/21 02:04:46 by mkaratzi         ###   ########.fr       */
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
		while (i < argc )
			if (!(make_from_one_string(a, argv[i++], &stack_a)))
				return (ft_error_free(&stack_a, a, 1));
		i = sort_the_stack(&stack_a);
		if (!i)
			return (ft_error_free(&stack_a, a, 1));
		if (i < 7)
			solution = bruteforce(&stack_a, i, &solution);
		if (i >= 7)
			solution = smart_solution(&stack_a, i, &solution);
	}
	ft_error_free(&stack_a, a, 0);
	print_solution(&solution->solution, 0);
	free(solution);
	return (1);
}
