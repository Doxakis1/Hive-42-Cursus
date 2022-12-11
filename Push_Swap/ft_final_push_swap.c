/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:40:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/12 01:19:35 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

int main(int argc, char const **argv)
{
	int i;
	char **a;
	t_instructions *solution;
	t_stack *stack_a;

	a = NULL;
	stack_a = NULL;
	solution = malloc(sizeof(t_instructions));
	i = 0;
	if (argc < 2 || !solution)
		return 0;
	solution->solution = NULL;
	if (argc == 2)
		{
			a = ft_split(argv[1], ' ');
			while (a[i])
				if (!(add_to_stack(&stack_a, a[i++])))
						return (ft_error_free(&stack_a, a));
		}
	i = 1;
	while ( i < argc && argc > 2)
		if (!(add_to_stack(&stack_a, argv[i++])))
				return (ft_error_free(&stack_a, a));
	i = sort_the_stack(&stack_a);
	if (!i)
		return (ft_error_free(&stack_a, a));
	if (i < 101)
		solution = bruteforce(&stack_a, i, &solution);
	if (solution->solution != NULL)
	{
		while (stack_a)
		{
			ft_printf("\nWE GOT: %d,  in sorted pos: %d\n", stack_a->nbr, stack_a->sorted);
			stack_a = stack_a->next;
		}
		
	}
	return 0;
}

int incriment(t_instructions **to_increase, int stacksize)
{
	int i;

	i = 0;

	while ((*to_increase)->solution[i] != '\0')
	{ 
		if ((*to_increase)->solution[i] < '8' && calculatenext(&(*to_increase), i, stacksize))
			{
				(*to_increase)->solution[i] = ((*to_increase)->solution[i] + 1);
				return (1);
			}
		else
			{
				(*to_increase)->solution[i] = '0';
				(*to_increase)->solution[i] = calculatenext(&(*to_increase), i, stacksize);
				i++;
			}
	} 
	return (0);
}

int calculatenext(t_instructions **string, int index, int stacksize)
{
	int b_stack;
	int a_stack;
	int i;
	int c;

	a_stack = stacksize;
	c = (*string)->solution[index];
	b_stack = 0;
	i = 0;
	while (i < index)
	{
		if((*string)->solution[i] == '2')
			{
				b_stack--;
				a_stack++;
			}
		if((*string)->solution[i] == '5')
			{
				b_stack++;
				a_stack--;
			}
		i++;
	}
	while(c <= '8')
	{
		c++;
		if (c > '5' || c == '2')
		{
			if (c == '2' && b_stack > 1)
				return (c);
			if (c > '5' && b_stack > 2)
				return (c);
		}
		if (c == '3' || c == '4')
		{
			if (a_stack >= 2)
				return (c);
		}
		if (c == '5')
			if (a_stack >= 1)
				return (c);
		if (c == '1' )
		{
			if (i >= 1)
				if((*string)->solution[i - 1] != '1')
					return (c);
			if (i < 1)
				return (c);
		}
			


	}
	//ft_printf("We here %d", a_stack);
	return (0);
}

t_instructions *bruteforce(t_stack **stack_a, int stacksize, t_instructions **solution)
{
	int k;
	int j;

	k = stacksize * 3;
	j = 0;
	(*solution)->solution = (char *)malloc(sizeof(char) * (k + 1));
	if (!(*solution)->solution)
		return NULL;
	(*solution)->solution[k] = '\0';
	while (j < k)
		(*solution)->solution[j++] = '0';
	while (incriment(&(*solution), stacksize))
	{
		if(checks_out(&(*stack_a), &(*solution), stacksize))
			return ((*solution));
	}
	free((*solution)->solution);
	(*solution)->solution = NULL;
	return ((*solution));
}
int	checks_out(t_stack **stack_a, t_instructions **solution, int size)
{
	t_stack *current;
	current = *stack_a;

	while (current != NULL)
	{
		
		if (!math_check(&(*solution), current->fixed, current->sorted, size))
			return (0);
		current = current->next; 
		//printf("solution so far: %s\n",(*solution)->solution);
	}
	printf("solution: %s",(*solution)->solution);
	return (1);
}
int	math_check(t_instructions **solved, long fixed, long sorted, long stack_size)
{
	int i;
	long b_stack;
	int a_stack;

	a_stack = stack_size;
	b_stack = 0;
	i = 0;
	// ft_printf("Here we have insturction: %c and %d and %d\n", (*solved)->solution[i] , sorted, stack_size);
	while((*solved)->solution[i]  != '\0' && (a_stack + b_stack) == stack_size)
	{	
		if ((*solved)->solution[i] == '1')
		{
			if (a_stack < 2)
				return 0;
			if (fixed == 1)
				fixed = 2;
			else if (fixed == 2)
				fixed = 1;
		}
		else if ((*solved)->solution[i] == '6')
		{
			if (b_stack < 2)
				return 0;
			if (fixed == -1)
				fixed = -2;
			else if (fixed == -2)
				fixed = 1;
		}
		else if ((*solved)->solution[i] == '2')
		{
			if (b_stack > 1)
				return 0;
			if (fixed == -1)
				fixed = 1;
			else if (fixed != -1)
				fixed++;
			b_stack--;
			a_stack++;
		}
		else if ((*solved)->solution[i] == '5')
		{
			if (a_stack <= 1)
				return 0;
			if (fixed == 1)
				fixed = -1;
			else if (fixed != 1)
				fixed--;
			b_stack++;
			a_stack--;
		}
		else if ((*solved)->solution[i] == '3')
		{
			if (a_stack < 2)
				return 0;
			if (fixed == 1)
				fixed = a_stack;
			else  if (fixed != 1 && fixed > 0)
				fixed--;
		}
		else if ((*solved)->solution[i] == '7')
		{
			if (b_stack < 2)
				return 0;
			if (fixed == (-1))
				fixed = (-1)*(b_stack);
			else if (fixed != (-1) && fixed < 0)
				fixed++;
		}
		else if ((*solved)->solution[i] == '4')
		{
			if (a_stack < 2)
				return 0;
			if (fixed == a_stack)
				fixed = 1;
			else if (fixed > 0)
				fixed++;
		}
		else if ((*solved)->solution[i] == '8')
		{
			if (b_stack < 2)
				return 0;
			if (fixed == ((-1) * b_stack))
				fixed = -1;
			else if (fixed < 0)
				fixed--;
		}
		else if ((*solved)->solution[i] == '0')
			break ;
		i++;
	}
	// ft_printf("Here we have insturction: %s and && %d , %d and %d\n", (*solved)->solution , fixed, sorted, stack_size);
	if (sorted == fixed && a_stack == stack_size)
		{
			//ft_printf("Here we have sorted matching: %s and && %d , %d and %d\n", (*solved)->solution , fixed, sorted, stack_size);
			return (1);
		}
	return 0;
}