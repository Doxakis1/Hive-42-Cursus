/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:24 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/21 02:04:27 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	print_solution(char **solution, int i)
{
	while (solution && solution[0][i] != '\0' && solution[0][i] != '0')
	{
		if (solution[0][i] == '1')
			ft_printf("sa\n");
		else if (solution[0][i] == '2')
			ft_printf("pa\n");
		else if (solution[0][i] == '3')
			ft_printf("ra\n");
		else if (solution[0][i] == '4')
			ft_printf("rra\n");
		else if (solution[0][i] == '5')
			ft_printf("pb\n");
		else if (solution[0][i] == '6')
			ft_printf("sb\n");
		else if (solution[0][i] == '7')
			ft_printf("rb\n");
		else if (solution[0][i] == '8')
			ft_printf("rrb\n");
		i++;
	}
	if (solution[0])
		free(solution[0]);
	return (0);
}