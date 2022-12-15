/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:22:06 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 10:56:19 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_instructions	*smart_solution(t_stack **stack_a, int size,
				t_instructions **sol)
{
	int	k;
	int	j;

	k = size * 30;
	j = 0;
	(*sol)->solution = (char *)malloc(sizeof(char) * (k + 1));
	if (!(*sol)->solution)
		return (NULL);
	(*sol)->solution[k] = '\0';
	while (j < k)
		(*sol)->solution[j++] = '0';
	construct_solution(stack_a, size, sol);
	free((*sol)->solution);
	(*sol)->solution = NULL;
	return ((*sol));
}

int	construct_solution(t_stack **a_st, int size, t_instructions **sol)
{
	t_stack	*b_st;
	t_stack *current_a;
	t_stack *current_b;

	current_a = *a_st;
	b_st = NULL;
	if (!(create_b_stack(&b_st, size)))
		return (0);
	current_b = b_st;
	while (current_a != NULL)
	{
		ft_printf("We have: %d\n", current_a->nbr);
		current_b->nbr = current_a->nbr;
		current_a = current_a->next;
		current_b = current_b->next;
	}
	while (b_st != NULL)
	{
		ft_printf("We have: %d\n", b_st->nbr);
		b_st = b_st->next;
	}
	return (1);
}

int	create_b_stack(t_stack **b_st, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!(add_to_stack(b_st, "0")))
			return (0);
		i++;
	}
	return (1);
}