/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:14:40 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/08 09:40:16 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			step;

	string = (unsigned char *)s;
	step = 0;
	while (step < n)
	{
		if (string[step] == (unsigned char)c)
			return (&string[step]);
		if (string[step] == '\0')
			break ;
		step++;
	}
	if ((unsigned char)c == 0 && string[step] != '\0')
		return (NULL);
	return (NULL);
}
