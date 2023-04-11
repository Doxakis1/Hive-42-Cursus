/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:37:44 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:49:13 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_push_swap.h"

int	main(int argc, char const **argv)
{
	int				i;
	char			**a;
	t_instructions	*solution;
	t_stack			stack_a[1000];

	a = NULL;
	while (i < 1000)
	{
		ft_bzero(&stack_a[i], sizeof(t_stack));
		i++;
	}
	solution = malloc(sizeof(t_instructions));
	i = 1;
	if (argc >= 2 && solution)
	{
		solution->solution = NULL;
		i = make_the_stack(&stack_a[0], argv, argc);
		i = sort_the_stack(stack_a);
		if (!i)
			return (ft_error_free(&stack_a, a, 1));
		if (i < 7)
			solution = bruteforce(stack_a, i, &solution);
		if (i >= 7)
			solution = (void *)0;
	}
	return (1);
}
