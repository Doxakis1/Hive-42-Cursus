/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:44:27 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:41:33 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long ft_atou(const char *str)
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

int ft_atou_to_dest(const char *str, long *dst)
{
	long	sign;
	int		i;

	*(dst) = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9' 
			&& *(dst) <= 2147483647 && *(dst) >= -2147483648)
			*(dst) = *(dst) * 10 + str[i] - '0';
		else if (str[i] == ' ')
			return (i + 1) ;
		else if (((str[i] <= '0' || str[i] >= '9') && str[i] != ' ') || 
			(*(dst) >= 2147483647 || *(dst) <= -2147483648))
		{
			*(dst) = 2147483648;
			return (ft_strlen(str));
		}
			
		i++;
	}
	*(dst) *= sign;
	return (i);
}