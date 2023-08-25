/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:17:17 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 04:00:22 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Global variables are forbidden!
• Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
◦ number_of_philosophers: The number of philosophers and also the number
of forks.
◦ time_to_die (in milliseconds)
◦ time_to_eat (in milliseconds)
◦ time_to_sleep (in milliseconds)
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
• Each philosopher has a number ranging from 1 to number_of_philosophers.
• Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and
	philosopher number N + 1.

About the logs of your program:
• Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.
• A displayed state message should not be mixed up with another message.
• A message announcing a philosopher died should be displayed no more than 10 ms
after the actual death of the philosopher.
• Again, philosophers should avoid dying!

Program name philo

Turn in files Makefile, *.h, *.c, in directory philo/

Makefile NAME, all, clean, fclean, re

Arguments number_of_philosophers time_to_die time_to_eat time_to_sleep
	[number_of_times_each_philosopher_must_eat]

External functs. 
 
gettimeofday, 
pthread_create,
pthread_detach, 
pthread_join, 

pthread_mutex_lock,
pthread_mutex_unlock
*/

#include "philo.h"

static int	free_everything(t_monitor *monitor, t_philo **philos)
{
	int	index;

	index = monitor->philo_counter - 1;
	destroy_forks(monitor->forks, index);
	destroy_death_state(monitor->death_state);
	free(*philos);
	return (0);
}

int	main(int argc, char const *argv[])
{
	long			inputarray[5];
	t_monitor		monitor;
	t_philo			*philos;

	(void)philos;
	if (check_invalid_arguments(argc, argv, &inputarray[0]))
		return (print_args_error());
	if (inputarray[0] == 1)
		return (print_loner_error());
	if (initialize_monitor(&monitor, inputarray[0]))
		return (print_monitor_error());
	if (initialize_philos(inputarray, &monitor, &philos))
		return (print_philo_creation_error()
			+ free_everything(&monitor, &philos));
	start_simulation(&monitor, &philos);
	(void)free_everything(&monitor, &philos);
	return (0);
}
