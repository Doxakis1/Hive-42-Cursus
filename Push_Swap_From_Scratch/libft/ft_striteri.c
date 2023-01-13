/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:16:41 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/08 12:07:32 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	string_len;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	string_len = ft_strlen(s);
	while (i < string_len)
	{
		f(i, &s[i]);
		i++;
	}
}
