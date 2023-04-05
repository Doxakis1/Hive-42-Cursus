/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_the_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:06:41 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 06:14:18 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	make_the_stack(t_stack *stack_a, const char **av, int ac)
{
	int i = 0;
	int j = 1;
	int k = 0;
	int stack_size;
	
	while(j < ac)
	{
		i = 0;
		while(av[j][i] != '\0')
			i = i + ft_atou_to_dest(av[j], &(stack_a[k++].nbr));
		j++;
	}
	stack_size = k - 1;
	while (--k >= 0)
	{
		if (stack_a[k].nbr == 2147483648)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else 
				stack_a[k].in_use = 1;
	}
	link_the_stack(&stack_a[0], stack_size);
	return(stack_size + 1);
}

int	link_the_stack(t_stack *stack_a, int stacksize)
{
	int i;

	i  = 0;

	stack_a[0].previous = &stack_a[stacksize];
	stack_a[stacksize].next = &stack_a[0];
	while(i < stacksize)
	{
		stack_a[i].next = &stack_a[i + 1];
		i++;
	}
	i = stacksize;
	while (i > 0)
	{
		stack_a[i].previous = &stack_a[i - 1];
		i--;
	}
	return (1);
}