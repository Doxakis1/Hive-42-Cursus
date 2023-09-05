/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 03:33:21 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/23 05:46:52 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_args_error(void)
{
	write(2, "Sorry, but this is not how you run philo!\n", 42);
	write(2, "Philo takes either 4 or 5 arguments!\n", 37);
	write(2, "All arguments should be positive int size integers!\n", 52);
	write(2, "The following arguments should be provided", 42);
	write(2, " in correct order:\n", 19);
	write(2, "1)number_of_philosophers\n", 25);
	write(2, "2)time_to_die\n", 14);
	write(2, "3)time_to_eat\n", 14);
	write(2, "4)time_to_sleep\n", 16);
	write(2, "Optional 5)number_of_times_each_philosopher_must_eat\n", 53);
	return (1);
}

int	print_monitor_error(void)
{
	write(2, "Sorry, the initialization of the monitor failed :c\n", 51);
	return (1);
}

int	print_philo_creation_error(void)
{
	write(2, "Sorry, the creation of philos has failed :c\n", 44);
	return (1);
}

int	print_loner_error(long array[5])
{
	long start_time;

	start_time = get_time();
	printf("%zu philo 1 is thinking\n%zu philo 1 grabbed afork\n",
		get_time() - start_time, get_time() - start_time);
	usleep(array[1] * 1000);
	printf("%zu philo 1 died\n", get_time() - start_time);
	return (1);
}
