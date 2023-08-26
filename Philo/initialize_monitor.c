/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:26:47 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 04:06:16 by mkaratzi         ###   ########.fr       */
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
	monitor->printer.alive = ALIVE;
	monitor->philo_threads = initialize_philo_threads(monitor->philo_counter);
	monitor->forks = initialize_forks(monitor->philo_counter);
	if (!monitor->forks || !monitor->philo_threads)
		return (1 + destroy_forks(monitor->forks, --(monitor->philo_counter))
			+ free_philo_threads(monitor->philo_threads));
	return (0);
}
