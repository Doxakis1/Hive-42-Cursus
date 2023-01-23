/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/23 13:38:36 by mkaratzi         ###   ########.fr       */
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
	}
		
	
	return (1);
}

int sort_the_stack(t_stack *stack_a, int stack_size)
{
		t_stack	*stack_b;
		int		bitshift;
		int		i = 0;
		bitshift = 7;		
		stack_b = NULL;

	
	while(stack_a)
	{
		ft_printf("stack_a->nbr is %d\n", stack_a->nbr);
		push_to_stack(&stack_a, &stack_b, bitshift);
	}
	while (i-- >= 0 && stack_a != NULL)
	{
		ft_printf("At A stack stayed:%d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	while (stack_b->nbr != 12)
	{
		ft_printf("At B stack stayed:%d\n", stack_b->nbr);
		stack_b = stack_b->next;
	}
		return (1);
}