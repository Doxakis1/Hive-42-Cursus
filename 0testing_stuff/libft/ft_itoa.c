/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:11:51 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/15 07:41:57 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		digits(int number);

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;
	long	number;

	counter = digits(n);
	number = n;
	str = malloc(sizeof(char) * counter + 1);
	if (str == NULL)
		return (NULL);
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

int	digits(int number)
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
