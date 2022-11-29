/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:52:33 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/29 14:23:56 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_stack	*make_stack_a(char *str);
t_stack	*add_to_stack(t_stack *head, char *next);
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
	return (head);
}

t_stack	*add_to_stack(t_stack *head, char *next)
{
	t_stack	*next;
	int		pos;

	next = make_empty(next);
	if (!next)
		return (NULL);
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
	head->previous = 0;
	head->rel = 0;
	return (head);
}