#include "philo.h"

void	freeall(t_details *details)
{
	int	i;

	i = -1;
	while (++i < details->philo_count)
	{
		pthread_mutex_destroy(&details->philo[i].fork_l);
		pthread_mutex_destroy(details->philo[i].fork_r);
	}
	free(details->philo);
	pthread_mutex_destroy(&details->printer_lock);
	pthread_mutex_destroy(&details->death_lock);
	pthread_mutex_destroy(&details->eat_lock);
	pthread_mutex_destroy(&details->dead);
}

int	main(int argc, char **argv)
{
	t_details	details;
	long		inputarray[5];

	if (check_invalid_arguments(argc, argv, &inputarray[0]))
		return (print_args_error());
	if (inputarray[0] == 1)
		return (print_loner_error());
	if (initialize_simulation(&details, inputarray) == 1)
	{
		free(details.philo);
		return (0);
	}
	initialize_philo(&details);
	freeall(&details);
	return (0);
}
