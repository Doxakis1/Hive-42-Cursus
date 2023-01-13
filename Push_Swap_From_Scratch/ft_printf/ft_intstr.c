/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:47:44 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/09 19:22:53 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intstr(char *src, int count)
{
	ssize_t	a;

	if (src == NULL)
	{
		write(1, "(null)", 6);
		count += 6;
		return (count);
	}
	a = ft_intstrlen((const char *)src);
	write(1, src, a);
	count += a;
	return (count);
}
