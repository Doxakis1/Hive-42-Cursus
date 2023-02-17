/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:19 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/02/17 16:50:21 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(void)
{
	struct sigaction my_handler;

	my_handler.sa_sigaction = (void *)0;
	sigemptyset(&(my_handler.sa_mask));
	printf("Server is now running and our pid is: %d\n", getpid());
	return 0;
}
