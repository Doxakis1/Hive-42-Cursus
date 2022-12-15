/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_into_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 05:12:23 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/15 05:20:16 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*make_into_str(long n, int size)
{
	int		counter;
	char	*str;
	long	number;
	int		filler;

	filler = 0;
	counter = fixed_size(size);
	number = n;
	str = malloc(sizeof(char) * counter + 1);
	if (str == NULL)
		return (NULL);
	while (filler < counter)
		str[filler++] = '0';
	str[counter--] = '\0';
	while (number)
	{
		str[counter--] = number % 10 + '0';
		number = number / 10;
	}
	return (str);
}

int	fixed_size(int size)
{
	int	x;

	x = 0;
	while (size >= 1)
	{
		size /= 10;
		x++;
	}
	return (x);
}
