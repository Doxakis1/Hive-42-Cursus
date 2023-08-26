/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_print_states.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:46:39 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 03:29:57 by mkaratzi         ###   ########.fr       */
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
	my_strlcpy(print_states[0], "%lld %d has taken a fork\n", 26);
	my_strlcpy(print_states[1], "%lld %d is eating\n", 19);
	my_strlcpy(print_states[2], "%lld %d is sleeping\n", 21);
	my_strlcpy(print_states[3], "%lld %d is thinking\n", 21);
	my_strlcpy(print_states[4], "%lld %d died\n", 14);
	return (0);
}
