/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:16:08 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 03:17:19 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
