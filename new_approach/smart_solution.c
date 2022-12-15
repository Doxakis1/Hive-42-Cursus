/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:22:06 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 04:25:33 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_instructions	*smart_solution(t_stack **stack_a, int size,
					t_instructions **sol)
{
	int	k;
	int	j;

	k = size * 3000;
	j = 0;
	(*sol)->solution = (char *)malloc(sizeof(char) * (k + 1));
	if (!(*sol)->solution)
		return (NULL);
	(*sol)->solution[k] = '\0';
	while (j < k)
		(*sol)->solution[j++] = '0';
	if ((checks_out(&(*stack_a), &(*sol), size)))
		return ((*sol));
	while (new_incriment(&(*sol), size))
	{
		if (checks_out(&(*stack_a), &(*sol), size))
			return ((*sol));
	}
	free((*sol)->solution);
	(*sol)->solution = NULL;
	return ((*sol));
}