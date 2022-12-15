/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:59:44 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 03:12:46 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	new_incriment(t_instructions **sol, int size);
int	calculatenext(t_instructions **string, int index, int size);
int	checks_out(t_stack **stack_a, t_instructions **solution, int size);
int	math_check(t_instructions **sol, long fixed, long sorted, long stack_size);
int	calculate_stacksize(char *instructions, int size, int index, int a);

int	new_incriment(t_instructions **sol, int size)
{
	int	i;
	int	fornow;

	i = 0;
	while ((*sol)->solution[i] != '\0')
	{
		fornow = calculatenext(&(*sol), i, size);
		if ((*sol)->solution[i] < '8' && fornow)
		{
			(*sol)->solution[i] = fornow;
			return (1);
		}
		else
		{
			(*sol)->solution[i] = '1';
			i++;
		}
	}
	return (0);
}

int	calculate_stacksize(char *instructions, int size, int index, int a)
{
	int	b_stack;
	int	i;
	int	a_stack;

	a_stack = size;
	b_stack = 0;
	i = 0;
	while (i < index)
	{
		if (instructions[i] == '2')
		{
			b_stack--;
			a_stack++;
		}
		if (instructions[i] == '5')
		{
			b_stack++;
			a_stack--;
		}
		i++;
	}
	if (a == 1)
		return (a_stack);
	return (b_stack);
}

int	calculatenext(t_instructions **string, int index, int size)
{
	int	b_stack;
	int	a_stack;
	int	c;

	a_stack = calculate_stacksize((*string)->solution, size, index, 1);
	b_stack = calculate_stacksize((*string)->solution, size, index, 2);
	c = (*string)->solution[index];
	while (c <= '8')
	{
		c++;
		if (c == '1')
			if (index < 1 || (*string)->solution[index - 1] != '1')
				return (c);
		if (c == '2' && b_stack >= 1 && (*string)->solution[index - 1] != '5')
			return (c);
		if (c > '5' && b_stack > 2)
			return (c);
		if (c == '3' || c == '4')
			if (a_stack >= 2)
				return (c);
		if (c == '5')
			if (a_stack >= 1 && (*string)->solution[index - 1] != '2')
				return (c);
	}
	return (0);
}

int	checks_out(t_stack **stack_a, t_instructions **solution, int size)
{
	t_stack	*current;

	current = *stack_a;
	while (current != NULL)
	{	
		if (!math_check(&(*solution), current->fixed, current->sorted, size))
			return (0);
		current = current->next;
	}
	return (1);
}

int	math_check(t_instructions **sol, long fixed, long sorted, long stack_size)
{
	int	i;
	int	b_stack;
	int	a_stack;

	a_stack = stack_size;
	b_stack = 0;
	i = 0;
	while ((*sol)->solution[i] != '\0' && (*sol)->solution[i] != '0')
	{	
		if ((*sol)->solution[i] == '1' && a_stack >= 2)
		{
			if (fixed == 1)
				fixed = 2;
			else if (fixed == 2)
				fixed = 1;
		}
		else if ((*sol)->solution[i] == '6' && b_stack >= 2)
		{
			if (fixed == -1)
				fixed = -2;
			else if (fixed == -2)
				fixed = -1;
		}
		else if ((*sol)->solution[i] == '2' && b_stack >= 1)
		{
			if (fixed == -1)
				fixed = 1;
			else if (fixed < -1)
				fixed++;
		}
		else if ((*sol)->solution[i] == '5' && a_stack >= 1)
		{
			if (fixed == 1)
				fixed = -1;
			else if (fixed > 1)
				fixed--;
		}
		else if ((*sol)->solution[i] == '3' && a_stack >= 2)
		{
			if (fixed == 1)
				fixed = a_stack;
			else if (fixed > 1)
				fixed--;
		}
		else if ((*sol)->solution[i] == '7' && b_stack >= 2)
		{
			if (fixed == (-1))
				fixed = (-1) * (b_stack);
			else if (fixed < -1)
				fixed++;
		}
		else if ((*sol)->solution[i] == '4' && a_stack >= 2)
		{
			if (fixed == a_stack)
				fixed = 1;
			else if (fixed > 0)
				fixed++;
		}
		else if ((*sol)->solution[i] == '8' && b_stack >= 2)
		{
			if (fixed == ((-1) * b_stack))
				fixed = -1;
			else if (fixed < 0)
				fixed--;
		}
		else
			break ;
		a_stack = calculate_stacksize((*sol)->solution, stack_size, i, 1);
		b_stack = calculate_stacksize((*sol)->solution, stack_size, i, 2);
		i++;
	}
	if (sorted == fixed && a_stack == stack_size)
		return (1);
	return (0);
}