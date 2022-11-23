/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:40:17 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/02 11:29:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	b;
	int				i;

	b = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (b == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == b)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
