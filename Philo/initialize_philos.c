/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:26:47 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 05:44:43 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	initialize_parameters(long *inputarray, t_parameters *parameters)
{
	int	i;

	i = 1;
	parameters->time_to_die = (int)inputarray[i++];
	parameters->time_to_eat = (int)inputarray[i++];
	parameters->time_to_sleep = (int)inputarray[i++];
	parameters->times_eaten = (int)inputarray[i++];
	parameters->time_last_ate = 0;
}

static int	find_my_fork_two(int id,  int philo_count)
{
	if (id == philo_count - 1)
		return (id);
	if (id == 0)
		return (philo_count - 1);
	if (id % 2)
		return (id);
	return (id - 1);
}

static int	find_my_fork_one(int id, int philo_count)
{
	
	if (id == 0)
		return (0);
	if (id == philo_count - 1)
		return (id - 1);
	if (id == 0)
		return (0);
	if (id % 2)
		return (id - 1);
	return (id);
}

static int	initialize_loop(t_philo *philo, int id, t_monitor *monitor,
	t_parameters *myparameters)
{
	int		philo_count;
	int		check;
	

	philo_count = monitor->philo_counter;
	philo->parameters = *myparameters;
	philo->fork_two = &monitor->forks[find_my_fork_two(id, philo_count)];
	philo->fork_one = &monitor->forks[find_my_fork_one(id, philo_count)];
	philo->id = id + 1;
	philo_count = pthread_mutex_init(&philo->death_lock, NULL);
	philo->alive = ALIVE;
	check = pthread_mutex_init(&philo->eaten_lock, NULL);
	if (check)
		return (1);
	check = pthread_mutex_init(&philo->death_lock, NULL);
	if (check)
	{
		pthread_mutex_destroy(&philo->eaten_lock);
		return (1);
	}
	philo->printer = &monitor->printer;
	return (0);
}

static int	destroy_philos_until(t_philo *philos, int counter)
{
	static int x = 0;
	
	while (x < counter)
	{
		pthread_mutex_destroy(&philos[x].death_lock);
		pthread_mutex_destroy(&philos[x].eaten_lock);
		x++;
	}
	return (1);
}

int	initialize_philos(long array[5], t_monitor *monitor, t_philo **philos)
{
	t_parameters	myparameters;
	int				loop_counter;
	int				loop_check;

	initialize_parameters(array, &myparameters);
	loop_counter = 0;
	loop_check = 0;
	*philos = (t_philo *)malloc(sizeof(t_philo) * monitor->philo_counter);
	if (!*philos)
		return (1);
	while (loop_counter < monitor->philo_counter && !loop_check)
	{
		loop_check =initialize_loop(&((t_philo *)*philos)[loop_counter], loop_counter,
			monitor, &myparameters);
		loop_counter++;
	}
	if (loop_check)
		return (destroy_philos_until(*philos,loop_counter));
	return (0);
}
