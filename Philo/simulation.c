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

static int	check_dead(t_philo *philo, int philo_count)
{
	int loop;

	loop = -1;
	while (++loop < philo_count)
	{
		pthread_mutex_lock(&philo[loop].death_lock);
		if (get_time() - philo->parameters.time_last_ate
		> (long long)philo->parameters.time_to_die && !philo[loop].alive)
		{
			pthread_mutex_lock(&philo->printer->printer_lock);
			philo->printer->alive = NOT_ALIVE;
			printf(philo->printer->print_states[DIED], get_time()
				- philo->printer->time_since_start, philo->id);
			pthread_mutex_unlock(&philo->printer->printer_lock);
			pthread_mutex_unlock(&philo[loop].death_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo[loop].death_lock);
	}
	return (0);
}

static int check_meal_times(t_monitor *monitor, t_philo *philos)
{
	int ret;
	int loop;

	loop = 0;
	if (monitor->times_eaten_done <= 0)
		return (1);
	ret = monitor->times_eaten_done;
	while (loop < monitor->philo_counter)
	{
		pthread_mutex_lock(&philos[loop].eaten_lock);
		if (philos->parameters.times_eaten <= 0)
		{
			ret--;
			pthread_mutex_lock(&philos[loop].death_lock);
			philos[loop].alive = NOT_ALIVE;
			pthread_mutex_unlock(&philos[loop].death_lock);
		}
		pthread_mutex_unlock(&philos[loop].eaten_lock);
		loop++;
	}
	return ret;
}

static void	await_the_philos(t_monitor *monitor, t_philo *philos)
{
	static int			philo = 0;	

	monitor->printer.time_since_start = get_time();
	pthread_mutex_unlock(&monitor->printer.printer_lock);
	usleep(5000);
	while (1)
	{
		if (check_dead(philos, monitor->philo_counter) || !check_meal_times(monitor, philos))
			break ;
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

	pthread_mutex_lock(&monitor->printer.printer_lock);
	while (++loop_counter < monitor->philo_counter)
	{
		if (pthread_create(&monitor->philo_threads[loop_counter], NULL,
				(void *)philo_loop, (void *)(&philos[loop_counter])))
				monitor->printer.alive = NOT_ALIVE;
		usleep(100);
	}
	await_the_philos(monitor, philos);
}
