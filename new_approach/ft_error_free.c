/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:40:54 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 03:16:00 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_stack(t_stack **stack);

int	ft_error_free(t_stack **stack_a, char **split)
{
	int	i;

	i = 0;
	free_stack(stack_a);
	if (split != NULL)
	{
		while (split[i] != NULL)
			free(split[i++]);
		free(split[i]);
	}
	write(2, "Error\n", 7);
	return (0);
}

void	free_stack(t_stack **stack)
{
	if ((*stack)->next != NULL)
		free_stack(&(*stack)->next);
	free((*stack));
	return ;
}