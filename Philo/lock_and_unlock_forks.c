/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_and_unlock_forks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:52:21 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 00:02:47 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(pthread_mutex_t *lock, int *value, int *id, int *ret_value)
{
	(void)pthread_mutex_lock(lock);
	*ret_value = 0;
	if (*value == 0)
	{
		*value = *id;
		*ret_value = 1;
	}
	(void)pthread_mutex_unlock(lock);
	return ;
}

void	unlock_fork(pthread_mutex_t *lock, int *value)
{
	(void)pthread_mutex_lock(lock);
	*value = 0;
	(void)pthread_mutex_unlock(lock);
	return ;
}
