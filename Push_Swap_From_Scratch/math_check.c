/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:15:22 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/27 14:47:31 by mkaratzi         ###   ########.fr       */
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

long	check_move_for_a(int a_st, int b_st, int fixed, int move)
{
	if (move == '1' && a_st >= 2 && fixed == 1)
		return (2);
	if (move == '1' && a_st >= 2 && fixed == 2)
		return (1);
	if (move == '4' && a_st >= 2 && fixed == a_st)
		return (1);
	if (move == '4' && a_st >= 2 && fixed > 0)
		return (++fixed);
	if (move == '3' && a_st >= 2 && fixed == 1)
		return (a_st);
	if (move == '3' && a_st >= 2 && fixed > 1)
		return (--fixed);
	if (move == '2' && b_st >= 1 && fixed == -1)
		return (1);
	if (move == '2' && b_st >= 1 && fixed == -1)
		return (++fixed);
	return (fixed);
}
