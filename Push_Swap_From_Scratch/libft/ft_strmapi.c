/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:16:41 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:26:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	str_len;
	size_t	i;

	if (s == (void *)0 || f == (void *)0)
		return ((void *)0);
	str_len = ft_strlen(s);
	result = malloc(str_len + 1);
	if (result == (void *)0)
		return ((void *)0);
	i = 0;
	while (i < str_len)
	{
		result[i] = f(i, s[i]);
		++i;
	}
	result[i] = '\0';
	return (result);
}
