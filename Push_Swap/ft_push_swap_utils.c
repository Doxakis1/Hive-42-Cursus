/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:40:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/10 11:50:41 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:41:57 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/10 11:35:12 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

int add_to_stack(t_stack **head, const char *str)
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
	{
		current = current->next;
	}
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

t_stack	*create_empty(t_stack **item)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if(new)
		{
			new->nbr = 0;
			new->sorted = 0;
			new->fixed = 0;
			new->next = NULL;
		}
	item = &new;
	return (*item);
}

int ft_error_free(t_stack **stack_a, char **split)
{
	int i;

	i = 0;
	free_stack(stack_a);
	if (split != NULL)
		{
			while (split[i] != NULL)
				free(split[i++]);
			free(split[i]);
		}
	ft_printf("Error\n");
	return (0);
}

void free_stack(t_stack **stack)
{
	if ((*stack)->next != NULL)
		free_stack(&(*stack)->next);
	free((*stack));
	return ;
}

int sort_the_stack(t_stack **stack_a)
{
	long 	i;
	long	j;
	short	test;
	t_stack *current;

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
	assignfixed(stack_a);
	return ((j - 1));
}

void assignfixed(t_stack **stack)
{
	long fixed;
	t_stack *current;

	current = *stack;
	fixed = 1;
	while ( current != NULL)
		{
			current->fixed = fixed;
			fixed++;
			current = current->next;
		}
	return ;
}

short find_next_smallest(t_stack **stack_a, long j)
{
	t_stack	*current;
	t_stack *smallest;

	current = *stack_a;
	smallest = NULL;
	
	while (current != NULL)
	{
		if ( current->sorted == 0 && smallest == NULL)
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
