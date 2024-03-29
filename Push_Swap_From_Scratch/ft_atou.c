/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:44:27 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/06/07 17:53:45 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	ft_atou(const char *str)
{
	long	final;
	long	sign;
	long	i;

	final = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9'
			&& final <= 2147483647 && final >= -2147483648)
			final = final * 10 + str[i] - '0';
		else if (str[i] == ' ')
			break ;
		else if ((str[i] <= '0' || str[i] >= '9') && str[i] != ' ')
			return (2147483648);
		i++;
	}
	return (sign * final);
}

static int	check_zero(int i, long *dst)
{
	if (*(dst) == 0 && i == 1)
	{
		*(dst) = 2147483648;
	}
	return (i);
}

int	ft_atou_to_dest(const char *str, long *dst, int sign, int i)
{
	*(dst) = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9'
			&& *(dst) <= 2147483648)
			*(dst) = *(dst) * 10 + str[i] - '0';
		else if (str[i] == ' ' && i++)
			break ;
		else if ((!ft_isdigit(str[i]) && str[i] != ' ')
			|| (*(dst) >= 2147483648 && str[i + 1] != ' '))
		{
			*(dst) = 2147483648;
			return (ft_strlen(str));
		}
		i++;
	}
	*(dst) *= sign;
	return (check_zero(i, dst));
}
