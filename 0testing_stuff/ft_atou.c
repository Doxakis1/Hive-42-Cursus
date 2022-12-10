/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:10:59 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/09 18:47:21 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atou(const char *str)
{
	long long	final;
	long long	sign;

	final = 0;
	sign = 1;
	if (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		return (2147483648);
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			final = final * 10 + *str - '0';
		if (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\f' || *str == '\r' || *str == '\v')
			return (2147483648);
		if (final > 2147483647 || final < -2147483648)
			return (2147483648);
		str++;
	}
	return (sign * final);
}