/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:26:47 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 04:18:36 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_monitor(t_monitor *monitor, long philo_count)
{
	int				counter;

	counter = 0;
	if (initialize_print_states(monitor->printer.print_states))
		return (1);
	monitor->philo_counter = (int)philo_count;
	monitor->philo_threads = initialize_philo_threads(monitor->philo_counter);
	monitor->death_state = initialize_death_state();
	monitor->forks = initialize_forks(monitor->philo_counter);
	if (!monitor->death_state || !monitor->forks)
		return (1 + destroy_forks(monitor->forks,
				--(monitor->philo_counter))
			+ destroy_death_state(monitor->death_state)
			+ free_philo_threads(monitor->philo_threads));
	return (0);
}
