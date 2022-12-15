/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:39:43 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 05:05:57 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*create_empty(t_stack **item)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->nbr = 0;
		new->sorted = 0;
		new->fixed = 0;
		new->str = NULL;
		new->next = NULL;
	}
	item = &new;
	return (*item);
}