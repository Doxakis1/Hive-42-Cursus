/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:24 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 02:57:53 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	print_solution(char *solution)
{
	int	i;

	i = 0;
	while (solution && solution[i] != '\0' && solution[i] != '0')
	{
		if (solution[i] == '1')
			ft_printf("sa\n");
		else if (solution[i] == '2')
			ft_printf("pa\n");
		else if (solution[i] == '3')
			ft_printf("ra\n");
		else if (solution[i] == '4')
			ft_printf("rra\n");
		else if (solution[i] == '5')
			ft_printf("pb\n");
		else if (solution[i] == '6')
			ft_printf("sb\n");
		else if (solution[i] == '7')
			ft_printf("rb\n");
		else if (solution[i] == '8')
			ft_printf("rrb\n");
		i++;
	}
	return (0);
}