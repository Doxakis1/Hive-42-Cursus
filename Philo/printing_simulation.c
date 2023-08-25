/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:47:43 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/25 04:21:36 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulation_printer(int id, int state, t_printer *printer)
{
	pthread_mutex_lock(&printer->fork_lock);
	get_time(&printer->current_time);
	printer->current_time -= printer->time_since_start;
	printf(printer->print_states[state], printer->current_time, id);
}

void	print_last_message(t_monitor *monitor, int check)
{
	if (check == -1)
		printf("Failed to start threads");
	else
		simulation_printer(check, DIED, &monitor->printer);
}
