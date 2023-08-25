/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_death_state.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:45:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/24 02:53:06 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_death_state(t_death_state *death_state)
{
	(void)pthread_mutex_destroy(&(death_state->death_lock));
	free(death_state);
	return (0);
}

t_death_state	*initialize_death_state(void)
{
	t_death_state	*death_state;

	death_state = (t_death_state *)malloc(sizeof(t_death_state));
	if (!death_state)
		return (NULL);
	if (pthread_mutex_init(&(death_state->death_lock), NULL))
	{
		destroy_death_state(death_state);
		return (NULL);
	}
	death_state->death = 0;
	return (death_state);
}
