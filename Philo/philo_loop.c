/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 04:22:43 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 05:48:23 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_my_state(int state, t_philo *my_data)
{
	pthread_mutex_lock(&my_data->printer->printer_lock);
	if (my_data->printer->alive == ALIVE)
	{
		printf(my_data->printer->print_states[state], get_time()
			- my_data->printer->time_since_start, my_data->id);
		pthread_mutex_unlock(&my_data->printer->printer_lock);
		return ;
	}
	pthread_mutex_unlock(&my_data->printer->printer_lock);
	my_data->alive = NOT_ALIVE;
}
static void	philo_eat(t_philo *my_data)
{
	pthread_mutex_lock(&my_data->fork_one->fork_lock);
	print_my_state(TOOK_FORK, my_data);
	pthread_mutex_lock(&my_data->fork_two->fork_lock);
	print_my_state(TOOK_FORK, my_data);
	print_my_state(EATING, my_data);
	pthread_mutex_lock(&my_data->death_lock);
	my_data->parameters.time_last_ate = get_time();
	pthread_mutex_unlock(&my_data->death_lock);
	sleep_mod(my_data, my_data->parameters.time_to_eat);
	pthread_mutex_lock(&my_data->eaten_lock);
	my_data->parameters.times_eaten--;
	pthread_mutex_unlock(&my_data->eaten_lock);
	pthread_mutex_unlock(&my_data->fork_one->fork_lock);
	pthread_mutex_unlock(&my_data->fork_two->fork_lock);
}

static void	philo_sleep(t_philo *my_data)
{
	print_my_state(SLEEPING, my_data);
	sleep_mod(my_data, my_data->parameters.time_to_sleep);
}

static void	philo_think(t_philo *my_data)
{
	print_my_state(THINKING, my_data);
}

void	philo_loop(void *data)
{
	t_philo		*my_data;

	my_data = (t_philo *)data;
	pthread_mutex_lock(&my_data->printer->printer_lock);
	pthread_mutex_unlock(&my_data->printer->printer_lock);
	my_data->parameters.time_last_ate = get_time();
	if (my_data->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (check_death(my_data))
			return ;
		philo_eat(my_data);
		philo_sleep(my_data);
		philo_think(my_data);
	}
	return ;
}
