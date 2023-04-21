/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:23:21 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/21 13:52:38 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		long_digits(long number);

char	*ft_ltoa(long n)
{
	int		counter;
	char	*str;
	long	number;

	counter = long_digits(n);
	number = n;
	str = malloc(sizeof(char) * counter + 1);
	if (str == (void *)0)
		return ((void *)0);
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	if (number == 0)
		str[0] = '0';
	str[counter--] = '\0';
	while (number)
	{
		str[counter--] = number % 10 + '0';
		number = number / 10;
	}
	return (str);
}

int	long_digits(long number)
{
	int	counter;

	counter = 0;
	if (number <= 0)
		counter++;
	while (number)
	{
		counter++;
		number = number / 10;
	}
	return (counter);
}
