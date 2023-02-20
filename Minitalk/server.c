/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:19 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/02/20 16:13:22 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

active_pid_t receiving_pid;

void handle_signals(int signal, siginfo_t *singal_info, void *context)
{
	(void)context;
	if (!receiving_pid.pid)
		receiving_pid.pid = singal_info->si_pid;
	ft_printf("we received a signal from: %d\n", singal_info->si_pid);
}

int main(void)
{
	receiving_pid.pid = 0;
	receiving_pid.signal = 0;
	struct sigaction my_handler;

	my_handler.sa_sigaction = &handle_signals;
	my_handler.sa_flags = SA_SIGINFO;
	sigemptyset(&(my_handler.sa_mask));
	sigaction(SIGTSTP, &my_handler, NULL);
	ft_printf("Our server has the pid: %d\n", getpid());
	while(!receiving_pid.pid)
	{
		ft_printf("We have receiving_pid = %d\n", receiving_pid.pid);
		sleep(2);
	}
	return 0;
}
