/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:38:46 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/02/20 16:07:33 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "ft_printf.h"
# include <unistd.h>
# include <signal.h>

typedef struct active_pid_s{
	int pid;
	int signal;
} active_pid_t;



#endif