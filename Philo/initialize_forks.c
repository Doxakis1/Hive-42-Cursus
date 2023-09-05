/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:45:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/24 05:06:07 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_forks(t_fork	*forks, int index)
{
	while (index >= 0)
	{
		(void)pthread_mutex_destroy(&(forks[index].fork_lock));
		index--;
	}
	free(forks);
	return (0);
}

t_fork	*initialize_forks(const int fork_count)
{
	t_fork		*forks;
	int			loop_counter;

	forks = (t_fork *)malloc(sizeof(t_fork) * fork_count);
	if (!forks)
		return (forks);
	loop_counter = 0;
	while (loop_counter < fork_count)
	{
		if (pthread_mutex_init(&(forks[loop_counter].fork_lock), NULL))
		{
			destroy_forks(forks, loop_counter);
			return (NULL);
		}
		loop_counter++;
	}
	return (forks);
}
