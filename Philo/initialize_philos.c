/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:26:47 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 04:29:32 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// typedef struct s_parameters{
// 	int			time_to_die;
// 	int			time_to_eat;
// 	int			time_to_sleep;
// 	int			times_to_eat;
// 	int			times_eaten;
// 	int			time_last_ate;
// 	long long	time_last_checked;
// }t_parameters;
static void	initialize_parameters(long *inputarray, t_parameters *parameters)
{
	int	i;

	i = 1;
	parameters->time_to_die = (int)inputarray[i++];
	parameters->time_to_eat = (int)inputarray[i++];
	parameters->time_to_sleep = (int)inputarray[i++];
	parameters->times_to_eat = (int)inputarray[i++];
	parameters->times_eaten = 0;
	parameters->time_last_ate = 0;
	parameters->time_last_checked = 0;
}

int	find_my_left_fork(int id, int philo_count)
{
	(void)philo_count;
	return (id);
}

int	find_my_right_fork(int id, int philo_count)
{
	if (id == philo_count - 1)
		return (0);
	return (id + 1);
}

static int	initialize_loop(t_philo *philo, int id, t_monitor *monitor,
	t_parameters *myparameters)
{
	int		count;

	count = monitor->philo_counter;
	philo->parameters = *myparameters;
	philo->left_fork = &monitor->forks[find_my_left_fork(id, count)];
	philo->right_fork = &monitor->forks[find_my_right_fork(id, count)];
	philo->id = id + 1;
	philo->printer = &monitor->printer;
	philo->death_state = monitor->death_state;
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
