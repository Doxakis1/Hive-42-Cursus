/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrive_and_modify.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:52:21 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 01:01:17 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	retrieve_value(pthread_mutex_t *lock, int *value, int *pointer)
{
	(void)pthread_mutex_lock(lock);
	*pointer = *value;
	(void)pthread_mutex_unlock(lock);
	return ;
}

void	update_value(pthread_mutex_t *lock, int *old_value, int new_value)
{
	(void)pthread_mutex_lock(lock);
	*old_value = new_value;
	(void)pthread_mutex_unlock(lock);
	return ;
}
