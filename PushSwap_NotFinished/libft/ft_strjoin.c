/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:46:28 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/02 07:17:00 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	calculatedsize;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	calculatedsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = malloc(calculatedsize);
	if (!final)
		return (NULL);
	ft_strlcpy(final, s1, calculatedsize);
	ft_strlcat(final, s2, calculatedsize);
	return (final);
}
