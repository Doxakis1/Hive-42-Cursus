/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:52:21 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 04:49:07 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_time(long long *last_time, int *time_last_ate)
{
	long long		time_in_milliseconds;
	long long		temp;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time_in_milliseconds = (current_time.tv_sec) * 1000;
	temp = time_in_milliseconds - *last_time;
	*last_time = time_in_milliseconds;
	if (time_last_ate)
		*time_last_ate += (int)temp / 1000;
	return ;
}

void	get_time(long long *dst)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	*dst = (current_time.tv_sec) * 1000 + (current_time.tv_usec / 1000);
}
