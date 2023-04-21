/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:50:24 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/21 16:53:10 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	print_solution(char *solution, int i)
{
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
		i++;
	}
	if (solution)
		free(solution);
	return (0);
}
