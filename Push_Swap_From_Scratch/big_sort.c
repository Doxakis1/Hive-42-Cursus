/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 07:29:24 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/24 19:39:14 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_highest_bit(int stack_size)
{
	int		max_bits;

	max_bits = 0;
	while ((stack_size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	check_sorted(t_stack *stack_a)
{
	t_stack	*current;
	int		check;

	current = stack_a;
	check = current->nbr;
	while (current->next->nbr != check)
	{
		if (current->nbr >= current->next->nbr)
			return (EXIT_FAILURE);
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

void	big_sort(t_stack *stack_a, int stack_size, int i, int j)
{
	t_stack	*stack_b;
	t_stack	*dummy;
	int		max_bits;
	int		b_stack_size;

	dummy = NULL;
	stack_b = NULL;
	max_bits = get_highest_bit(stack_size);
	while (++i <= max_bits && check_sorted(stack_a))
	{
		j = 0;
		b_stack_size = 0;
		while (j++ < stack_size)
		{
			if (((stack_a->nbr >> i) & 1) == 1)
				rotate_move(&stack_a, 'a');
			else
			{
				push_to_stack(&stack_a, &stack_b, 'b', dummy);
				b_stack_size++;
			}	
		}
		while (b_stack_size-- != 0)
			push_to_stack(&stack_b, &stack_a, 'a', dummy);
	}
}
