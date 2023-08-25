/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_print_states.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:46:39 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 03:12:27 by mkaratzi         ###   ########.fr       */
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
	my_strlcpy(print_states[0], "%d Philo %d has taken a fork\n", 30);
	my_strlcpy(print_states[1], "%d Philo %d is eating\n", 23);
	my_strlcpy(print_states[2], "%d Philo %d is sleeping\n", 25);
	my_strlcpy(print_states[3], "%d Philo %d is thinking\n", 25);
	my_strlcpy(print_states[4], "%d Philo %d has died\n", 22);
	return (0);
}
