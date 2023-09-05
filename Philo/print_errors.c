/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 03:33:21 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/23 05:46:52 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_args_error(void)
{
	print_error("Sorry, but this is not how you run philo!\n");
	print_error("Philo takes either 4 or 5 arguments!\n");
	print_error("All arguments should be positive int size integers!\n");
	print_error("The following arguments should be provided");
	print_error(" in correct order:\n");
	print_error("1)number_of_philosophers\n");
	print_error("2)time_to_die\n");
	print_error("3)time_to_eat\n");
	print_error("4)time_to_sleep\n");
	print_error("Optional 5)number_of_times_each_philosopher_mustime_to_eat\n");
	return (1);
}

int	print_error(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		write(2, &str[index], 1);
	}
	return (1);
}

int	print_loner_error(void)
{
	print_error("Sorry, it takes atleast two to dine at this restaurant :c\n");
	return (1);
}
