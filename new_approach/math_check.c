/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:15:22 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 04:15:26 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	math_check(t_instructions **sol, long fixed, long sorted, long stack_size)
{
	int	i;
	int	b_st;
	int	a_st;

	a_st = stack_size;
	b_st = 0;
	i = 0;
	while ((*sol)->solution[i] != '\0' && (*sol)->solution[i] != '0' && fixed)
	{	
		if ((*sol)->solution[i] < '5')
			fixed = check_move_for_a(a_st, b_st, fixed, (*sol)->solution[i]);
		else
			fixed = check_move_for_a(a_st, b_st, fixed, (*sol)->solution[i]);
		a_st = calculate_stacksize((*sol)->solution, stack_size, i, 1);
		b_st = calculate_stacksize((*sol)->solution, stack_size, i, 2);
		i++;
	}
	if (sorted == fixed && a_st == stack_size)
		return (1);
	return (0);
}

long	check_move_for_a(int a_st, int b_st,int fixed, int move)
{
	if (move == '1' && a_st >= 2)
	{
		if (fixed == 1)
			fixed = 2;
		else if (fixed == 2)
			fixed = 1;
	}
	else if (move == '4' && a_st >= 2)
	{
		if (fixed == a_st)
			fixed = 1;
		else if (fixed > 0)
			fixed++;
	}
	else if (move == '3' && a_st >= 2)
	{
		if (fixed == 1)
			fixed = a_st;
		else if (fixed > 1)
			fixed--;
	}
	else if (move == '2' && b_st >= 1)
	{
		if (fixed == -1)
			fixed = 1;
		else if (fixed < -1)
			fixed++;
	}
	else
		return (0);
	return (fixed);
}

long	check_move_for_b(int a_st, int b_st,int fixed, int move)
{
	if (move == '6' && b_st >= 2)
	{
		if (fixed == -1)
			fixed = -2;
		else if (fixed == -2)
			fixed = -1;
	}
	else if (move == '5' && a_st >= 1)
	{
		if (fixed == 1)
			fixed = -1;
		else if (fixed > 1)
			fixed--;
	}
	else if (move == '7' && b_st >= 2)
	{
		if (fixed == (-1))
			fixed = (-1) * (b_st);
		else if (fixed < -1)
			fixed++;
	}
	else if (move == '8' && b_st >= 2)
	{
		if (fixed == ((-1) * b_st))
			fixed = -1;
		else if (fixed < 0)
			fixed--;
	}
	else
		return (0);
	return (fixed);
}