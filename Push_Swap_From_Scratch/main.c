/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/24 13:09:43 by mkaratzi         ###   ########.fr       */
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
		int		stack_size_holder = stack_size;
		int		i = 0;
				
		stack_b = NULL;
		i = 0;
		bitshift = -1;
		while(stack_a && stack_size)
		{
			i = 0;
			bitshift++;
			
			while (i < stack_size && stack_a)
			{
				if ((stack_a->nbr >> bitshift) % 2 == 0)
					{
						push_to_stack(&stack_a, &stack_b, 'b');
						b_stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_a, 'a');
					}
			stack_size = stack_size_holder - b_stack_size;
			i++;
		 	}
		}
		bitshift = 0;
		while(stack_b && b_stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < b_stack_size && stack_b)
			{
				if ((stack_b->nbr >> bitshift) % 2 == 1)
					{
						push_to_stack(&stack_b, &stack_a, 'a');
						stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_b, 'b');
					}
			b_stack_size = stack_size_holder - stack_size;
			i++;
		 	}
		}
		bitshift = 1;
		while(stack_a && stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < stack_size && stack_a)
			{
				if ((stack_a->nbr >> bitshift) % 2 == 0)
					{
						push_to_stack(&stack_a, &stack_b, 'b');
						b_stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_a, 'a');
					}
			stack_size = stack_size_holder - b_stack_size;
			i++;
		 	}
		}
		bitshift = 2;
		while(stack_b && b_stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < b_stack_size && stack_b)
			{
				if ((stack_b->nbr >> bitshift) % 2 == 1)
					{
						push_to_stack(&stack_b, &stack_a, 'a');
						stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_b, 'b');
					}
			b_stack_size = stack_size_holder - stack_size;
			i++;
		 	}
		}
		bitshift = 2;
		while(stack_a && stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < stack_size && stack_a)
			{
				if ((stack_a->nbr >> bitshift) % 2 == 0)
					{
						push_to_stack(&stack_a, &stack_b, 'b');
						b_stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_a, 'a');
					}
			stack_size = stack_size_holder - b_stack_size;
			i++;
		 	}
		}
		bitshift = 3;
		while(stack_b && b_stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < b_stack_size && stack_b)
			{
				if ((stack_b->nbr >> bitshift) % 2 == 1)
					{
						push_to_stack(&stack_b, &stack_a, 'a');
						stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_b, 'b');
					}
			b_stack_size = stack_size_holder - stack_size;
			i++;
		 	}
		}
		bitshift = 3;
		while(stack_a && stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < stack_size && stack_a)
			{
				if ((stack_a->nbr >> bitshift) % 2 == 0)
					{
						push_to_stack(&stack_a, &stack_b, 'b');
						b_stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_a, 'a');
					}
			stack_size = stack_size_holder - b_stack_size;
			i++;
		 	}
		}
		bitshift = 4;
		while(stack_b && b_stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < b_stack_size && stack_b)
			{
				if ((stack_b->nbr >> bitshift) % 2 == 1)
					{
						push_to_stack(&stack_b, &stack_a, 'a');
						stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_b, 'b');
					}
			b_stack_size = stack_size_holder - stack_size;
			i++;
		 	}
		}
		bitshift = 4;
		while(stack_a && stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < stack_size && stack_a)
			{
				if ((stack_a->nbr >> bitshift) % 2 == 0)
					{
						push_to_stack(&stack_a, &stack_b, 'b');
						b_stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_a, 'a');
					}
			stack_size = stack_size_holder - b_stack_size;
			i++;
		 	}
		}
		bitshift = 5;
		while(stack_b && b_stack_size && bitshift <= 5)
		{
			i = 0;
			bitshift++;
			while (i < b_stack_size && stack_b)
			{
				if ((stack_b->nbr >> bitshift) % 2 == 1)
					{
						push_to_stack(&stack_b, &stack_a, 'a');
						stack_size++;
					}
				else
					{
						reverse_rotate_move(&stack_b, 'b');
					}
			b_stack_size = stack_size_holder - stack_size;
			i++;
		 	}
		}
		i = 0;
		// ft_printf("Our A+stack size is: %d\nOur B+stack size is: %d\n", stack_size, b_stack_size);
		// ft_printf("Our bstack size is: %d\n", stack_size);
		while (++i <= stack_size && stack_a)
		{
			ft_printf("A stack: %d\n", stack_a->nbr);
			stack_a = stack_a->next;
		}
		i = 0;
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