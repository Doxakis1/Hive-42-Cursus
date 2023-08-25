/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 05:02:50 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 05:13:36 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_the_forks(t_philo *my_data, int *check_death)
{
	int	right_fork;
	int	left_fork;

	lock_fork(&my_data->right_fork->fork_lock,
		&my_data->right_fork->fork_ownership, &my_data->id , &right_fork);
	if (right_fork)
	{
		simulation_printer(my_data->id, TOOK_FORK, my_data->printer);
		lock_fork(&my_data->left_fork->fork_lock,
			&my_data->left_fork->fork_ownership,  &my_data->id , &left_fork);
		if (left_fork)
			return (1);
		unlock_fork(&my_data->right_fork->fork_lock,
			&my_data->right_fork->fork_ownership);
	}
	return (0);
}

void	start_eating(t_philo *my_data, int *check_death)
{
	int			eating_time;

	eating_time = 0;
	update_death(my_data, check_death);
	my_data->parameters.time_last_ate = 0;
	simulation_printer(my_data->id, EATING, my_data->printer);
	while (!(*check_death) && my_data->parameters.time_to_eat <= eating_time)
	{
		update_death(my_data, check_death);
		usleep(2000);
		eating_time += 2;
	}
	return ;
}
