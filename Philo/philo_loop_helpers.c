/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:04:20 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/09/05 17:43:50 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *my_data)
{
	int	ret;

	ret = ALIVE;
	pthread_mutex_lock(&my_data->death_lock);
	ret = my_data->alive;
	pthread_mutex_unlock(&my_data->death_lock);
	return (ret);
}

void	sleep_mod(t_philo *my_data, long time_to_sleep)
{
	long	current_time;

	current_time = get_time();
	while (!check_death(my_data)
		&& (get_time() - current_time) < time_to_sleep)
	{
		usleep(500);
	}
	return ;
}
