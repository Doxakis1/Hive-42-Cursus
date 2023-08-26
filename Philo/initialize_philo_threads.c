/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philo_threads.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:45:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/26 03:44:44 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_philo_threads(pthread_t	*philo_threads)
{
	free(philo_threads);
	return (0);
}

pthread_t	*initialize_philo_threads(const int philo_count)
{
	pthread_t	*philo_thread;
	int			loop_counter;

	loop_counter = 0;
	philo_thread = (pthread_t *)malloc(sizeof(pthread_t) * philo_count);
	if (!philo_thread)
		return (philo_thread);
	while (loop_counter < philo_count)
	{
		philo_thread[loop_counter] = 0;
		loop_counter++;
	}
	return (philo_thread);
}
