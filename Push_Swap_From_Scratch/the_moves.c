/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:43:51 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/23 15:29:20 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

int reverse_rotate_move(t_stack **stack_given, int identifier)
{
	if (!stack_given)
		return (0);
	stack_given[0] = stack_given[0]->next;
	ft_printf("rr%c\n", identifier);
	
	return (1);
}

int rotate_move(t_stack **stack_given, int identifier)
{
	if (!stack_given)
		return (0);
	stack_given[0] = stack_given[0]->previous;
	ft_printf("r%c\n", identifier);
	
	return (1);
}
int push_to_stack(t_stack **src, t_stack **dst, int character)
{
	t_stack	*current_src;

	if (!src[0])
		return (0);
	current_src = src[0];
	(src[0]->previous)->next = current_src->next;	
	(src[0]->next)->previous = current_src->previous;
	if(src[0]->nbr != src[0]->next->nbr)
		src[0] = current_src->next;
	else
		src[0] = NULL;
	if (!dst[0])
	{
		
		dst[0] = current_src;
		dst[0]->next = dst[0];
		dst[0]->previous = dst[0];
		
	}
	else
	{
		current_src->next = dst[0];
		current_src->previous = dst[0]->previous;
		dst[0]->previous->next = current_src;
		dst[0]->previous = current_src;
		dst[0] = current_src;
		
	}
	ft_printf("p%c\n", character);
	return (1);
}