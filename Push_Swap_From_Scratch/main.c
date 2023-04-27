/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/27 14:32:25 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char const **av)
{
	int				stack_size;
	t_stack			stack_a[MAX_STACK_SIZE];
	t_instructions	*solution;

	stack_size = 0;
	solution = malloc(sizeof(t_instructions));
	if (!solution || ac < 2)
		return (1);
	while (stack_size < MAX_STACK_SIZE)
		ft_bzero(&stack_a[stack_size++], sizeof(t_stack));
	stack_size = 0;
	stack_size = make_the_stack(&stack_a[0], av, ac, 1);
	if (!stack_size || !sort_the_stack(&stack_a[0], stack_size))
	{
		free(solution);
		return (write(2, "Error\n", 6));
	}	
	if (stack_size <= 6)
		bruteforce(&stack_a[0], stack_size, &solution);
	else
		big_sort(&stack_a[0], stack_size, (-1), 0);
	if (stack_size <= 6)
		print_solution(solution->solution, 0);
	free(solution);
	return (0);
}
