/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:47:03 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/08 11:26:20 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*final;

	size = ft_strlen(s);
	final = malloc(size + 1);
	if (final != NULL)
	{
		ft_strlcpy(final, s, (size + 1));
		return (final);
	}
	return (NULL);
}
