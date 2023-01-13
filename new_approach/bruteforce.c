/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:53:41 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/13 15:55:26 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_instructions	*bruteforce(t_stack **stack_a, int size, t_instructions **sol)
{
	int	k;
	int	j;

	k = size * 3;
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
