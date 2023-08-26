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
	parameters->times_to_eat = (int)inputarray[i++];
	parameters->time_last_ate = 0;
}

static int	find_my_left_fork(int id)
{
	return (id);
}

static int	find_my_right_fork(int id, int philo_count)
{
	if (id == philo_count - 1)
		return (0);
	return (id + 1);
}

static int	initialize_loop(t_philo *philo, int id, t_monitor *monitor,
	t_parameters *myparameters)
{
	int		philo_count;

	philo_count = monitor->philo_counter;
	philo->parameters = *myparameters;
	philo->times_eaten_done = &monitor->times_eaten_done;
	philo->left_fork = &monitor->forks[find_my_left_fork(id)];
	philo->right_fork = &monitor->forks[find_my_right_fork(id, philo_count)];
	philo->id = id + 1;
	philo->alive = ALIVE;
	philo->printer = &monitor->printer;
	return (0);
}

int	initialize_philos(long array[5], t_monitor *monitor, t_philo **philos)
{
	t_parameters	myparameters;
	int				loop_counter;

	initialize_parameters(array, &myparameters);
	loop_counter = 0;
	*philos = (t_philo *)malloc(sizeof(t_philo) * monitor->philo_counter);
	if (!philos)
		return (1);
	while (loop_counter < monitor->philo_counter)
	{
		initialize_loop(&((t_philo *)*philos)[loop_counter], loop_counter,
			monitor, &myparameters);
		loop_counter++;
	}
	return (0);
}
