/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:19 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/02/21 17:52:06 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

active_pid_t sender;

int ft_power_two(int exp) {
    int result = 1;

    while (exp > 0) {
        result *= 2;
        exp--;
    }
	ft_printf("Our result is %d", result);
    return result;
}

void handle_signals(int signal, siginfo_t *singal_info, void *context)
{
	(void)context;
	if (!sender.pid && signal == SIGUSR1)
		sender.pid = singal_info->si_pid;
	switch (signal)
	{
		case SIGUSR1:
			sender.signal = 1;
			break;
		case SIGUSR2:
			sender.signal = 2;
			break;
		default:
			break;
	}
}
int get_length(void)
{
	int length;
	int bits;
	int holder;

	bits = sizeof(int) * 8 - 1;
	sender.signal = 0;
	length = 0;
	holder = 0;
	while (bits)
	{
		switch (sender.signal)
		{
			case 0:
				kill(sender.pid, SIGUSR1);
				break ;
			case 1:
			{
				bits--;
				holder = ft_power_two((sizeof(int) * 8 - 1) - bits);
				length += holder;
				sender.signal = 0;
				break;
			}
			case 2:
			{
				bits--;
				sender.signal = 0;
				break;
			}	
			default:
				break;
		}
	}
	sender.msg_length = length + 1;
	return (length);
}
int get_character(void)
{
	int length;
	int bits;
	int holder;

	bits = sizeof(char) * 8 - 1;
	sender.signal = 0;
	length = 0;
	while (bits)
	{
		holder = 0;
		switch (sender.signal)
		{
			case 0:
				break ;
				//kill(sender.pid, SIGUSR1);
			case 1:
			{	
				bits--;
				holder = ft_power_two((sizeof(char) * 8 - 1) - bits);
				length += holder;
				sender.signal = 0;
				break;
			}
			case 2:
			{
				bits--;
				sender.signal = 0;
				break;
			}	
			default:
				break;
		}
	}
	sender.msg_length = length + 1;
	return (length);
}
int get_string(char **string, int size)
{
	int i;

	i  = 0;
	while (i < size)
	{
		string[0][i] = get_character();
		i++;
	}
	ft_printf("we made it here with size = %d\n", size);
	string[0][size] = '\0';
	ft_printf("The message received is: \n %s \n", string[0]);
	free(string[0]);
	return 0;
}
int main(void)
{
	struct sigaction my_handler;
	char *string;

	sender.pid = 0;
	sender.signal = 0;
	sender.msg_length = 0;
	my_handler.sa_sigaction = &handle_signals;
	my_handler.sa_flags = SA_SIGINFO;
	sigemptyset(&(my_handler.sa_mask));
	sigaction(SIGUSR1, &my_handler, NULL);
	sigaction(SIGUSR2, &my_handler, NULL);
	ft_printf("Our server has the pid: %d\n", getpid());
	while(1)
	{
		if (sender.pid)
		{
			ft_printf("We are receiving a message from pid = %d\n", sender.pid);
			ft_printf("The message is: %d characters long\n", get_length());
			string = (char *)malloc((sizeof(char) * sender.msg_length));
			if (!string)
				ft_printf("Failed to malloc for the message :c\n");
			else
				get_string(&string, (sender.msg_length - 1));
			sender.pid = 0;
			sender.msg_length = 0;
		}
			
		sleep(2);
	}
	return 0;
}
