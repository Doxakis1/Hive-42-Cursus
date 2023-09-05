#include "philo.h"

int	initialize_philo(t_details *details)
{
	int	i;

	details->t_start = get_time();
	i = -1;
	while (++i < details->philo_count)
	{
		details->philo[i].n = i + 1;
		details->philo[i].lastime_to_eat = 0;
		details->philo[i].fork_r = NULL;
		details->philo[i].details = details;
		details->philo[i].m_count = 0;
		pthread_mutex_init(&(details->philo[i].fork_l), NULL);
		if (i == details->philo_count - 1)
			details->philo[i].fork_r = &details->philo[0].fork_l;
		else
			details->philo[i].fork_r = &details->philo[i + 1].fork_l;
		if (pthread_create(&details->philo[i].thread, NULL, \
				&philo_loop, &(details->philo[i])) != 0)
			return (-1);
	}
	i = -1;
	while (++i < details->philo_count)
		if (pthread_join(details->philo[i].thread, NULL) != 0)
			return (-1);
	return (0);
}

int	initialize_simulation(t_details *details, long *numbers)
{
	pthread_mutex_init(&details->printer_lock, NULL);
	pthread_mutex_init(&details->death_lock, NULL);
	pthread_mutex_init(&details->eat_lock, NULL);
	pthread_mutex_init(&details->dead, NULL);
	details->alive_status = 0;
	details->philo = malloc(sizeof(t_philo) * details->philo_count);
	if (details->philo == NULL)
		return (print_error("Failed to malloc for philos\n"));
	details->philo_eat = 0;
	details->philo_count = numbers[0];
	details->time_to_die = numbers[1];
	details->time_to_eat = numbers[2];
	details->time_to_sleep = numbers[3];
	if (numbers[0] != -1)
		details->times_eaten = numbers[4];
	if (details->times_eaten == 0)
		return (print_error("Times eaten cannot be 0\n"));
	return (0);
}
