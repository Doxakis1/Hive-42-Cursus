/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_arguments.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 03:35:13 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/24 04:23:46 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_invalid_arguments(int argc, char const *argv[], long *inputarray)
{
	int	loop_counter;

	loop_counter = 0;
	if (argc != 5 && argc != 6)
		return (1);
	if (argc == 5)
		inputarray[4] = 0;
	while (++loop_counter < argc)
	{
		if (ft_atou_to_dest(argv[loop_counter], &inputarray[loop_counter - 1],
				1))
			return (1);
	}
	return (0);
}
