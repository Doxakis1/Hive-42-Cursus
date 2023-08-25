/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:52:21 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 05:16:04 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_death(t_philo *my_data, int *check_death)
{
	pthread_mutex_lock(&my_data->death_state->death_lock);
	*check_death = my_data->death_state->death;
	printf("We got %d\n", *check_death);
	pthread_mutex_unlock(&my_data->death_state->death_lock);
}

void	state_thinking(t_philo *my_data, int *check_death)
{
	update_death(my_data, check_death);
	if (!(*check_death))
	{
		simulation_printer(my_data->id, THINKING, my_data->printer);
	}
}

void	philo_loop(void *data)
{
	t_philo	*my_data;
	int		check_death;
	int		test;

	test = 0;
	my_data = (t_philo *)data;
	update_death(my_data, &check_death);
	get_time(my_data->parameters.time_last_checked);
	while (!check_death)
	{
		state_thinking(my_data, &check_death);
		if (get_the_forks(my_data, &check_death))
		{
			start_eating();
			if (!check_death)
				start_sleeping();
		}
	}
	return ;
}
