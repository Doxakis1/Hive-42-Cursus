/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/24 12:50:25 by mkaratzi         ###   ########.fr       */
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
		int		b_stack_size = 0;
		int		dirrection = 1;
		int		i = 0;
		bitshift = -1;		
		stack_b = NULL;

		i = 0;
		ft_printf("Our bstack size is: %d\n", stack_size);
		// while(stack_a)
		// {
		// 	i = 0;
		// 	stack_size = stack_size - b_stack_size;
		// 	bitshift++;
			while (i < stack_size && stack_a)
			{
				if ((stack_a->nbr >> 0) % 2 == 0)
					{
						push_to_stack(&stack_a, &stack_b, 'b');
						b_stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_a, 'a');
					}
			i++;
		 	}
			i = 0;
			stack_size = stack_size - b_stack_size;
			ft_printf("Our bstack size is: %d\n", b_stack_size);
			while (i < stack_size && stack_a)
			{
				if ((stack_a->nbr >> 1) % 2 == 0)
					{
						push_to_stack(&stack_a, &stack_b, 'b');
						b_stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_a, 'a');
					}
			i++;
		 	}
		// }
		i = 0;
		ft_printf("Our bstack size is: %d\n", stack_size);
		while (++i <= b_stack_size && stack_b)
		{
			ft_printf("B stack: %d\n", stack_b->nbr);
			stack_b = stack_b->next;
		}
		return (1);
}

int ft_power(int num, int power)
{
	int i;
	int copy;

	copy = num;
	i = 1;
	while (i < power)
		{
			num = copy * num;
			i++;
		}
	if(power <= 1)
		return (0);
	return (num);
}