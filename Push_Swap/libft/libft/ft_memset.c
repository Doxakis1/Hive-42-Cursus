/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:05:51 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/02 07:40:35 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int b, size_t c)
{
	size_t			i;
	unsigned char	*pointer;

	pointer = (unsigned char *)a;
	i = 0;
	while (i < c)
	{
		pointer[i] = (unsigned char)b;
		i++;
	}
	return (a);
}	
