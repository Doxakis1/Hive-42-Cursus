/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 04:22:43 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 05:42:12 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_my_state(int state, t_philo *my_data)
{
	pthread_mutex_lock(&my_data->printer->printer_lock);
	if (my_data->printer->alive == ALIVE)
	{
		printf(my_data->printer->print_states[state], get_time(), my_data->id);
		pthread_mutex_unlock(&my_data->printer->printer_lock);
		return ;
	}
	pthread_mutex_unlock(&my_data->printer->printer_lock);
	my_data->alive = NOT_ALIVE;
}

static void	check_times_eaten(t_philo *my_data)
{
	if (my_data->parameters.times_to_eat == 0)
	{
		*my_data->times_eaten_done--;
		my_data->alive = NOT_ALIVE;
	}
}

void	philo_loop(void *data)
{
	t_philo		*my_data;

	my_data = (t_philo *)data;
	my_data->parameters.time_last_ate = get_time();
	while (my_data->alive == ALIVE)
	{
		pthread_mutex_lock(&my_data->left_fork->fork_lock);
		print_my_state(TOOK_FORK, my_data);
		pthread_mutex_lock(&my_data->right_fork->fork_lock);
		print_my_state(TOOK_FORK, my_data);
		print_my_state(EATING, my_data);
		my_data->parameters.times_to_eat--;
		my_data->parameters.time_last_ate = get_time();
		usleep(my_data->parameters.time_to_eat * 1000);
		pthread_mutex_unlock(&my_data->left_fork->fork_lock);
		pthread_mutex_unlock(&my_data->right_fork->fork_lock);
		print_my_state(SLEEPING, my_data);
		usleep(my_data->parameters.time_to_sleep * 1000);
		print_my_state(THINKING, my_data);
	}
	return ;
}
