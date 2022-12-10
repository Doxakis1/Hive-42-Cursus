/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:50:05 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/08 10:46:25 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*destination;
	char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
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
