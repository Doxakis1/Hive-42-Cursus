/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:29:17 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/08 10:35:07 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absval(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if ((size_t) absval((char *) src - (char *) dst) >= n)
		while (n-- > 0)
			((char *) dst)[n] = ((char *) src)[n];
	return (dst);
}
