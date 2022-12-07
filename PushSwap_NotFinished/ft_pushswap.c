/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:52:33 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/07 19:45:01 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_stack	*make_stack_a(char *str);
t_stack	*add_to_stack(t_stack **head, char *next);
t_stack	*make_empty(t_stack *head);

int	main(int argc, char const *argv[])
{
	int		i;
	t_stack	*stack;

	i = 0;
	if (argc == 2)
	{
		stack = make_stack_a(argv[1]);
	}
	else if (argc > 2)
		while (i < argc)
			stack = add_to_stack(stack, argv[i++]);
	return (0);
}

t_stack	*make_stack_a(char *str)
{
	t_stack		*head;
	char		**created;
	int			i;

	i = 0;
	head = NULL;
	head = (t_stack *)malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
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

t_stack	*add_to_stack(t_stack **head, char *next)
{
	t_stack	*llnext;
	t_stack	*current;
	int		pos;

	pos = 0;
	current = head;
	llnext = make_empty(llnext);
	if (!llnext)
		return (NULL);
	while (current != NULL)
	{
		pos++;
		current = current->next;
	}
	llnext->pos = pos;
	llnext->
	return (*head);
}

t_stack	*make_empty(t_stack *head)
{
	head = (t_stack *)malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->cor = 0;
	head->curr = 0;
	head->next = 0;
	head->pos = 0;
	head->rel = 0;
	return (head);
}

int	addnumbers(int x, int y)
{
	int	i;
	int	ans;

	i = 0;
	ans = 0;
	while (i < x)
	{
		i++;
		ans++;
	}
	i = 0;
	while (i < y)
	{
		i++;
		ans++;
	}
	return (x + y);
}