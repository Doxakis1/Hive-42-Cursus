/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:16:08 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:43:58 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_bzero(void *a, size_t b)
{
	size_t	i;
	char	*pointer;

	i = 0;
	pointer = (char *)a;
	while (i < b)
	{
		pointer[i] = 0;
		i++;
	}
}
