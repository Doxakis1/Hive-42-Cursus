/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:17:17 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 05:17:59 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	free_everything(t_monitor *monitor, t_philo **philos)
{
	int	index;

	index = monitor->philo_counter - 1;
	destroy_forks(monitor->forks, index);
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
	if (initialize_monitor(&monitor, inputarray[0], inputarray[4]))
		return (print_monitor_error());
	if (initialize_philos(inputarray, &monitor, &philos))
		return (print_philo_creation_error()
			+ free_everything(&monitor, &philos));
	start_simulation(&monitor, philos);
	(void)free_everything(&monitor, &philos);
	return (0);
}
