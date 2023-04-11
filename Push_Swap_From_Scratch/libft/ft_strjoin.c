/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:46:28 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:26:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	calculatedsize;

	if (s1 == (void *)0 || s2 == (void *)0)
		return ((void *)0);
	calculatedsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = malloc(calculatedsize);
	if (!final)
		return ((void *)0);
	ft_strlcpy(final, s1, calculatedsize);
	ft_strlcat(final, s2, calculatedsize);
	return (final);
}
