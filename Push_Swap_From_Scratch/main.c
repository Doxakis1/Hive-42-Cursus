/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/25 16:56:24 by mkaratzi         ###   ########.fr       */
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

int check_more_rotates(t_stack **stack_given, int bitshift, int check, int stack_size)
{
	int j;
	t_stack current;
	current = *stack_given[0];
	j = 0;
	while( j < stack_size)
			{
				if((current.nbr / bitshift % 2) == check)
				{
					return (1);
				}
				current = *current.next;
				j++;
			}
	return (0);
}
int get_bitshift(int stack_size)
{
	int i;
	int answer;

	answer = 1;
	i = 1;
	while(stack_size / i)
	{
		i *= 2;
		answer++;
	}
		
	return (answer);

}
int sort_the_stack(t_stack *stack_a, int a_stack_size)
{
		t_stack	*stack_b;
		int		bitshift;
		int		unsorted = a_stack_size;
		int		b_stack_size = 0;
		int		stack_size_holder = a_stack_size;
		int		i = 0;
		int		j = 0;
		int		pushed_happened = 0;
		int		holder = get_bitshift(stack_size_holder);	
		stack_b = NULL;
		i = 0;
		bitshift = 8;
	while(bitshift)
	{
		bitshift = holder;
		while(stack_a)
		{
			j = 0;
			if (!check_more_rotates(&stack_a, bitshift, 0, a_stack_size))
				bitshift *= 2;
			while(stack_a && j < a_stack_size && check_more_rotates(&stack_a, bitshift, 0, a_stack_size))
			{
				if((stack_a->nbr / bitshift % 2) == 0)
				{
					push_to_stack(&stack_a, &stack_b, 'b');
					b_stack_size++;
					if (stack_b->nbr == unsorted)
					{
						stack_b->nbr += 2147483648;
						reverse_rotate_move(&stack_b, 'b');
						unsorted--;
						stack_size_holder--;
						b_stack_size--;
					}	
				}
				else
					reverse_rotate_move(&stack_a, 'a');
				j++;	
			}
				a_stack_size = stack_size_holder - b_stack_size;
				bitshift *= 2;
		}
		while(stack_b && stack_b->nbr < 2147483648)
		{
			if (stack_b->nbr == unsorted)
			{
				stack_b->nbr += 2147483648;
				reverse_rotate_move(&stack_b, 'b');
				unsorted--;
				stack_size_holder--;
				b_stack_size--;
				
			}	
			else
			{
				push_to_stack(&stack_b, &stack_a, 'a');
				a_stack_size++;
			}
			b_stack_size = stack_size_holder - a_stack_size;
		}
		holder--;
	}
	while(stack_b)
	{
		stack_b->nbr -= 2147483648;
		push_to_stack(&stack_b, &stack_a, 'a');
		a_stack_size++;
	}

		
		
		// ft_printf("Our A+stack size is: %d\nOur B+stack size is: %d\n", stack_size, b_stack_size);
		// ft_printf("Our bstack size is: %d\n", stack_size);
		i = 0;
		// while (++i <= a_stack_size && stack_a)
		// {
		// 	ft_printf("A stack: %d\n", stack_a->nbr);
		// 	stack_a = stack_a->next;
		// }
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