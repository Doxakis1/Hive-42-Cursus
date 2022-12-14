/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:38:52 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/14 17:05:10 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	add_to_stack(t_stack **head, const char *str)
{
	t_stack	*current;

	current = *head;
	if (*head == NULL)
	{
		(*head) = create_empty(head);
		if (*head)
		{
			(*head)->nbr = ft_atou(str);
			if ((*head)->nbr == 2147483648)
				return (0);
			return (1);
		}
	}
	while (current->next != NULL)
		current = current->next;
	current->next = create_empty(&current);
	current = current->next;
	if (current)
	{
		current->nbr = ft_atou(str);
		if (current->nbr == 2147483648)
			return (0);
	}
	return (1);
}