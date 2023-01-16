/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/16 16:36:33 by mkaratzi         ###   ########.fr       */
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
		ft_printf("We empting the position: %d for bytes: %d\n", stack_size, sizeof(t_stack));
		ft_bzero(&stack_a[stack_size], sizeof(t_stack));
		stack_a[stack_size].fixed = stack_size + 1;
		stack_size++;
	}
	stack_size = 0;
	if (ac >= 2)
		stack_size = make_the_stack(&stack_a[0], av);
		
	
	
	return (1);
}

int	make_the_stack(t_stack *stack_a, const char **av)
{
	int i = 0;
	int j = 0;
	
	(*av)++;
	while(i < 3)
	{
		if ((*av) != NULL)
			ft_printf("Hello suckers from %d and %d\n", ft_atou((*av)++), j++);
		i++;
	}
		
	return(0);
}