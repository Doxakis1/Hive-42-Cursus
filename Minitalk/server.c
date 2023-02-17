/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:19 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/02/17 17:21:07 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handle_signals(int signal, siginfo_t *singal_info)
{
	printf("we received a signal from: %d\n", singal_info->si_pid);
}

int main(void)
{
	struct sigaction my_handler;

	my_handler.__sigaction_u.__sa_sigaction = (void *)0;
	my_handler.__sigaction_u.__sa_handler = (void *)handle_signals;
	my_handler.sa_flags = SA_SIGINFO;
	sigemptyset(&(my_handler.sa_mask));
	sigaction(SIGTSTP, &my_handler, NULL);
	printf("Server is now running and our pid is: %d and our parent pid is: %d\n", getpid(), getppid());
	while(1)
	{
		
	}
	return 0;
}
