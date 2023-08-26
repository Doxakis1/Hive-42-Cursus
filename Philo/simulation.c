/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 04:23:49 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 05:49:05 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_alive(t_monitor *monitor, t_philo *philo)
{
	if (get_time() - philo->parameters.time_last_ate
		> (long long)philo->parameters.time_to_die)
	{
		pthread_mutex_lock(&monitor->printer.printer_lock);
		monitor->printer.alive = NOT_ALIVE;
		printf(monitor->printer.print_states[DIED], get_time(), philo->id);
		pthread_mutex_unlock(&monitor->printer.printer_lock);
	}
}

static void	await_the_philos(t_monitor *monitor, t_philo *philos)
{
	static volatile int	loop = 1;
	static int			philo = 0;	

	pthread_mutex_lock(&monitor->printer.printer_lock);
	loop = monitor->printer.alive;
	pthread_mutex_unlock(&monitor->printer.printer_lock);
	while (loop == ALIVE && monitor->times_eaten_done)
	{
		if (philos[philo].parameters.times_to_eat != 0)
			check_alive(monitor, &philos[philo]);
		pthread_mutex_lock(&monitor->printer.printer_lock);
		loop = monitor->printer.alive;
		pthread_mutex_unlock(&monitor->printer.printer_lock);
		philo = (philo + 1) % monitor->philo_counter;
	}
	philo = -1;
	while (++philo < monitor->philo_counter)
	{
		if (monitor->philo_threads[philo])
			pthread_join(monitor->philo_threads[philo], NULL);
	}
	return ;
}

void	start_simulation(t_monitor *monitor, t_philo *philos)
{
	static int	loop_counter = -1;

	while (++loop_counter < monitor->philo_counter)
	{
		if (pthread_create(&monitor->philo_threads[loop_counter], NULL,
				(void *)philo_loop, (void *)(&philos[loop_counter])))
				monitor->printer.alive = NOT_ALIVE;
		usleep(100);
	}
	usleep(500);
	await_the_philos(monitor, philos);
}
