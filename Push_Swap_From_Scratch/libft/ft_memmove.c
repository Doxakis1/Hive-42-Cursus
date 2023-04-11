/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:50:05 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:26:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*destination;
	char	*source;

	if (dst == (void *)0 && src == (void *)0)
		return ((void *)0);
	destination = (char *) dst;
	source = (char *) src;
	if (destination > source)
		while (n-- > 0)
			destination[n] = source[n];
	else
		while (n-- > 0)
			*(destination++) = *(source++);
	return (dst);
}
