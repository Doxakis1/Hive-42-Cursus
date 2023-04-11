/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 09:58:41 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char const **av)
{
	int				stack_size;
	t_stack			stack_a[MAX_STACK_SIZE];

	stack_size = 0;
	while (stack_size < MAX_STACK_SIZE)
	{
		ft_bzero(&stack_a[stack_size], sizeof(t_stack));
		stack_size++;
	}
	stack_size = 0;
	if (ac >= 2)
	{
		stack_size = make_the_stack(&stack_a[0], av, ac);
		sort_the_stack(&stack_a[0], stack_size);
		int i;
		i = 0;
		t_stack *curr;
		curr = &stack_a[0];
		while( i < stack_size)
		{
			ft_printf("We have the number: %d\n", curr->nbr);
			curr = curr->next;
			i++;
		}
	}
		
	
	return (1);
}