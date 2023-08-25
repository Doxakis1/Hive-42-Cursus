/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:52:21 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 04:46:54 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	halt_the_philos(t_death_state *death_state, int condition)
{
	if (condition == HALT)
		pthread_mutex_lock(&death_state->death_lock);
	else
		pthread_mutex_unlock(&death_state->death_lock);
	return ;
}

static void	start_the_threads(t_monitor *monitor, t_philo **philos_data)
{
	int			loop_counter;
	pthread_t	*list;
	t_philo		*data;

	data = *philos_data;
	loop_counter = 0;
	list = monitor->philo_threads;
	while (loop_counter < monitor->philo_counter)
	{
		if (pthread_create(&list[loop_counter], NULL, (void *)philo_loop,
				&(data[loop_counter])))
		{
			monitor->death_state->death = (-1);
			return ;
		}
		loop_counter++;
	}
}

static void	join_the_philos(pthread_t *list, int philo_count)
{
	int			loop_counter;

	loop_counter = 0;
	while (loop_counter < philo_count)
	{
		if (list[loop_counter] != 0)
			pthread_join(list[loop_counter], NULL);
		loop_counter++;
	}
}

static void	start_monitor_loop(t_monitor *monitor)
{
	int	check;

	check = 0;
	while (!check)
	{
		pthread_mutex_lock(&monitor->death_state->death_lock);
		check = monitor->death_state->death;
		pthread_mutex_unlock(&monitor->death_state->death_lock);
	}
}

void	start_simulation(t_monitor *monitor, t_philo **philos)
{
	int	check;

	check = 0;
	halt_the_philos(monitor->death_state, HALT);
	start_the_threads(monitor, philos);
	get_time(&monitor->printer.time_since_start);
	halt_the_philos(monitor->death_state, RESUME);
	start_monitor_loop(monitor);
	join_the_philos(monitor->philo_threads, monitor->philo_counter);
	update_value(&monitor->death_state->death_lock,
		&monitor->death_state->death, check);
	print_last_message(monitor, check);
	return ;
}
