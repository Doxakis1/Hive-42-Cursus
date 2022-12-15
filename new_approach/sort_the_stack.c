/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:42:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 10:30:29 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	assignfixed(t_stack **stack, int size);
short	find_next_smallest(t_stack **stack_a, long j);

int	sort_the_stack(t_stack **stack_a)
{
	long	i;
	long	j;
	short	test;
	t_stack	*current;

	i = 1;
	j = 1;
	current = *stack_a;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	while (j < i)
	{
		test = find_next_smallest(stack_a, j);
		if (!test)
			return (0);
		j++;
	}
	assignfixed(stack_a, i);
	return ((j - 1));
}

void	assignfixed(t_stack **stack, int size)
{
	long	fixed;
	t_stack	*current;

	current = *stack;
	fixed = 1;
	while (current != NULL)
	{
		current->fixed = fixed;
		current->str = make_into_str(fixed, size);
		fixed++;
		current = current->next;
	}
	return ;
}

short	find_next_smallest(t_stack **stack_a, long j)
{
	t_stack	*current;
	t_stack	*smallest;

	current = *stack_a;
	smallest = NULL;
	while (current != NULL)
	{
		if (current->sorted == 0 && smallest == NULL)
		{
			current->sorted = j;
			smallest = current;
		}
		if (current->sorted == 0 && current->nbr < smallest->nbr)
		{
			current->sorted = j;
			smallest->sorted = 0;
			smallest = current;
		}
		current = current->next;
		if (current != NULL && smallest != NULL)
			if (current->nbr == smallest->nbr)
				return (0);
	}
	return (1);
}
