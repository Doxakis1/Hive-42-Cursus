/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:25:38 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/02/21 17:50:21 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

active_pid_t receiver;

int send_length(int length)
{
	int bits;

	
	bits = sizeof(int) * 8 - 1;
	ft_printf("we made it here and size is %d\n", length);
	while (bits)
	{
		if(receiver.signal)
		{
			if (((length >> bits) % 2) == 1)
				kill(receiver.pid, SIGUSR1);
			else if (((length >> bits) % 2) == 0)
				kill(receiver.pid, SIGUSR2);
			receiver.signal = 0;
			bits--;
		}	
	}
	return (0);
}
void handle_signals(int signal, siginfo_t *singal_info, void *context)
{
	(void)context;
	(void)singal_info;
	switch (signal)
	{
		case SIGUSR1:
		{
			ft_printf("We got a SIGUSR1...\n");
			receiver.signal = 1;
			break;
		}
			
		case SIGUSR2:
			exit(ft_printf("Message was not delivered..."));
			break;
		default:
			break;
	}
}

int main(void)
{
	struct sigaction my_handler;
	char *string = "Hello there server\n";

	receiver.pid = 0;
	receiver.signal = 0;
	my_handler.sa_sigaction = &handle_signals;
	my_handler.sa_flags = SA_SIGINFO;
	sigemptyset(&(my_handler.sa_mask));
	sigaction(SIGUSR1, &my_handler, NULL);
	sigaction(SIGUSR2, &my_handler, NULL);
	ft_printf("Our client has the pid: %d\n", getpid());
	receiver.pid = 19776;
	kill(receiver.pid, SIGUSR1);
	while (1)
	{
		if (receiver.signal)
		{
			send_length(ft_strlen(string));
			break ;
		}
	}
	
	ft_printf("this is a test123\n");
	return 0;
}
