/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:33:04 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:26:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_for_match(const char *s1, const char *s2, size_t c);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	p;

	p = 0;
	n = 0;
	while (needle[n] != '\0')
		n++;
	if (n == 0)
		return ((char *)haystack);
	if (len == 0)
		return ((void *)0);
	while (p <= (len - n) && haystack[p] != '\0')
	{
		if (check_for_match((haystack + p), needle, n))
			return ((char *)(haystack + p));
		p++;
	}
	return ((void *)0);
}

int	check_for_match(const char *s1, const char *s2, size_t c)
{
	size_t	i;

	i = 0;
	while (i < c)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
