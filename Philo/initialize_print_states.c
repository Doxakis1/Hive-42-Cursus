/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_print_states.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:46:39 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/09/05 17:00:46 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	my_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;

	src_length = size;
	if (size == 0)
		return (src_length);
	while (--size > 0)
	{
		if (!*src)
			break ;
		*(dst++) = *(src++);
	}
	*dst = '\0';
	return (src_length);
}

int	initialize_print_states(char print_states[5][50])
{
	my_strlcpy(print_states[0], "%zu %d has taken a fork\n", 25);
	my_strlcpy(print_states[1], "%zu %d is eating\n", 18);
	my_strlcpy(print_states[2], "%zu %d is sleeping\n", 20);
	my_strlcpy(print_states[3], "%zu %d is thinking\n", 20);
	my_strlcpy(print_states[4], "%zu %d died\n", 13);
	return (0);
}

void	initialize_parameters(long *inputarray, t_parameters *parameters)
{
	int	i;

	i = 1;
	parameters->time_to_die = (int)inputarray[i++];
	parameters->time_to_eat = (int)inputarray[i++];
	parameters->time_to_sleep = (int)inputarray[i++];
	parameters->times_eaten = (int)inputarray[i++];
	parameters->time_last_ate = 0;
}
