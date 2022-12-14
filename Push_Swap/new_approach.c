/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_approach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:40:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/14 16:00:50 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

int main(int argc, char const **argv)
{
	int i;
	char **a;
	t_instructions *solution;
	t_stack *stack_a;

	a = NULL;
	stack_a = NULL;
	solution = malloc(sizeof(t_instructions));
	i = 0;
	if (argc < 2 || !solution)
		return 0;
	solution->solution = NULL;
	if (argc == 2)
		{
			a = ft_split(argv[1], ' ');
			while (a[i])
				if (!(add_to_stack(&stack_a, a[i++])))
						return (ft_error_free(&stack_a, a));
		}
	i = 1;
	while ( i < argc && argc > 2)
		if (!(add_to_stack(&stack_a, argv[i++])))
				return (ft_error_free(&stack_a, a));
	i = sort_the_stack(&stack_a);
	if (!i)
		return (ft_error_free(&stack_a, a));
	if (i < 101)
		solution = new_bruteforce(&stack_a, i, &solution);
	if (solution->solution != NULL)
	{
		while (stack_a)
		{
			ft_printf("\nWE GOT: %d,  in sorted pos: %d\n", stack_a->nbr, stack_a->sorted);
			stack_a = stack_a->next;
		}
		
	}
	return 0;
}

t_instructions *new_bruteforce(t_stack **stack_a, int stacksize, t_instructions **solution)
{
	int k;
	int j;

	k = stacksize * 3;
	j = 0;
	(*solution)->solution = (char *)malloc(sizeof(char) * (k + 1));
	if (!(*solution)->solution)
		return NULL;
	(*solution)->solution[k] = '\0';
	while (j < k)
		(*solution)->solution[j++] = '0';
	while (new_incriment(&(*solution), stacksize)s)
	{
		if(!1)
			return ((*solution));
	}
	free((*solution)->solution);
	(*solution)->solution = NULL;
	return ((*solution));
}

int	new_incriment(t_instructions **to_increase, int stacksize)
{
	int i;
	int k;
	static int mem = 0;

	k = 0;
	i = 0;
	stacksize = stacksize * 3;
	
	
	while((*to_increase)->solution[i] != '\0')
	{
		while(i <= k)
		{
			ft_printf("Right now is: %s", (*to_increase)->solution);
			if ((*to_increase)->solution[i] != '0' && (*to_increase)->solution[i] < '4')
					{
						(*to_increase)->solution[i] = ((*to_increase)->solution[i] + 1);
						return 1;
					}
			i++;
		}
		while (k < stacksize)
		{
			if ((*to_increase)->solution[i] == '0' && (*to_increase)->solution[i] != '\0')
					{
						(*to_increase)->solution[i] = ((*to_increase)->solution[i] + 1);
						k++;
						return 1;
					}
			else
				return (0);
		}
	}

	return (0);
}