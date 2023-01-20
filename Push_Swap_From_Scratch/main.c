/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/20 20:22:23 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char const **av)
{
	int				stack_size;
	t_stack			stack_a[MAX_STACK_SIZE];
	t_stack			stack_b[MAX_STACK_SIZE];

	stack_size = 0;
	while (stack_size < MAX_STACK_SIZE)
	{
		ft_bzero(&stack_a[stack_size], sizeof(t_stack));
		stack_a[stack_size].fixed = stack_size + 1;
		stack_size++;
		ft_bzero(&stack_b[stack_size], sizeof(t_stack));
		stack_b[stack_size].fixed = stack_size + 1;
	}
	stack_size = 0;
	if (ac >= 2)
		stack_size = make_the_stack(&stack_a[0], &stack_b[0], av, ac);
		
	
	
	return (1);
}

int	make_the_stack(t_stack *stack_a, t_stack *stack_b, const char **av, int ac)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	
	while(j < ac)
	{
		i = 0;
		while(av[j][i] != '\0')
			i = i + ft_atou_to_dest(av[j], &(stack_a[k++].nbr));
		j++;
	}
	while (--k > 0)
	{
		if (stack_a[k].nbr == 2147483648)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else 
			{
				stack_a[k].in_use = 1;
				stack_b[k].in_use = 1;
			}
	}
		
			

		
	return(0);
}