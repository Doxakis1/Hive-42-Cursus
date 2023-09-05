/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:04:20 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/09/05 17:04:28 by mkaratzi         ###   ########.fr       */
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

void	sleep_mod(t_philo *my_data, long long time_to_sleep)
{
	long long	current_time;
	long long	ll_time_to_sleep;

	ll_time_to_sleep = (long long)time_to_sleep;
	current_time = get_time();
	while (!check_death(my_data)
		&& (get_time() - current_time) < ll_time_to_sleep)
	{
		usleep(500);
	}
	return ;
}
