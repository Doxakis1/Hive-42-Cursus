/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:44:27 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/01/16 16:34:01 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (str[i] == ' ')
			break ;
		else
			return (2147483648);
		i++;
	}
	return (sign * final);
}