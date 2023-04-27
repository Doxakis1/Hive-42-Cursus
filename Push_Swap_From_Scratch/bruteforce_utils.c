/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:59:44 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/27 14:45:18 by mkaratzi         ###   ########.fr       */
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
		if ((*sol)->solution[i] < '4' && fornow)
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
	int	b_st;
	int	i;
	int	a_st;

	a_st = size;
	b_st = 0;
	i = 0;
	while (i < index)
	{
		if (instructions[i] == '2')
		{
			b_st--;
			a_st++;
		}
		if (instructions[i] == '5')
		{
			b_st++;
			a_st--;
		}
		i++;
	}
	if (a == 1)
		return (a_st);
	return (b_st);
}

int	calculatenext(t_instructions **string, int index, int size)
{
	int	b_st;
	int	a_st;
	int	c;

	a_st = calculate_stacksize((*string)->solution, size, index, 1);
	b_st = calculate_stacksize((*string)->solution, size, index, 2);
	c = (*string)->solution[index];
	while (c <= '8')
	{
		c++;
		if (c == '1')
			if (index < 1 || (*string)->solution[index - 1] != '1')
				return (c);
		if (c == '2' && b_st >= 1 && (*string)->solution[index - 1] != '5')
			return (c);
		if (c > '5' && b_st > 2)
			return (c);
		if (c == '3' || c == '4')
			if (a_st >= 2)
				return (c);
		if (c == '5')
			if (a_st >= 1 && (*string)->solution[index - 1] != '2')
				return (c);
	}
	return (0);
}

int	checks_out(t_stack **stack_a, t_instructions **solution, int size)
{
	t_stack	*current;
	int		i;

	current = *stack_a;
	i = 0;
	while (i++ < size)
	{	
		if (!math_check(&(*solution), current->fixed, current->nbr, size))
			return (0);
		current = current->next;
	}
	return (1);
}
