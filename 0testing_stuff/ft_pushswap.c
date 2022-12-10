/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:52:33 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/09 16:59:30 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_stack	*make_stack_a(const char *str);
t_stack	*add_to_stack(t_stack *head, const char *number);
t_stack	*make_empty(t_stack *head);

int	main(int argc, char const *argv[])
{
	int		i;
	t_stack	*stack;

	i = 1;
	if (argc == 2)
	{
		stack = make_stack_a(argv[1]);
	}
	else if (argc > 2)
		while (i < argc)
			stack = add_to_stack(stack, argv[i++]);
	while (stack)
	{
		printf("Our number is:%d \n", stack->val);
		stack = stack->next;
	}
	return (0);
}

t_stack	*make_stack_a(const char *str)
{
	t_stack		*head;
	char		**created;
	int			i;

	i = 0;
	head = NULL;
	created = ft_split(str, ' ');
	while (created[i] != NULL)
	{
		head = add_to_stack(head, created[i++]);
	}
	while (i >= 0)
	{
		free(created[i--]);
	}
	return (head);
}

t_stack	*add_to_stack(t_stack *head, const char *number)
{
	t_stack	*llnext;
	t_stack	*current;
	int		pos;

	pos = 0;
	current = head;
	llnext = make_empty(llnext);
	if (!llnext)
		return (NULL);
	if (current == NULL)
		head = llnext;
	else
	{
		while (current->next != NULL)
		{	
			pos++;
			current = current->next;
		}
		current->next = llnext;
	}
	llnext->pos = ++pos;
	llnext->val = ft_atou(number);
	return (head);
}

t_stack	*make_empty(t_stack *empty)
{
	empty = (t_stack *)malloc(sizeof(t_stack));
	if (!empty)
		return (NULL);
	empty->cor = 0;
	empty->curr = 0;
	empty->next = 0;
	empty->pos = 0;
	empty->val = 0;
	return (empty);
}

// t_stack copy_item(t_stack *item, )
// {

// }
