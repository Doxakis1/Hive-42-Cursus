/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_to_dest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:44:27 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/08/23 03:20:28 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	ft_atou_to_dest(const char *str, long *dst, int sign)
{
	int	i;

	i = 0;
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
		if (!ft_isdigit(str[i]) || (*(dst) >= 2147483648) || sign < 1)
		{
			*(dst) = 2147483648;
			return (1);
		}
		i++;
	}
	if (*(dst) == 0)
		return (1);
	return (0);
}
