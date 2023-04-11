/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:01:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:26:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*create_final(char const *given, int start, int length);

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			j;
	int			final_length;
	char		*final;

	if (s1 == (void *)0 || set == (void *)0)
		return ((void *)0);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, (int)s1[i]))
		i++;
	while (j >= 0 && ft_strchr(set, (int)s1[j]))
		j--;
	final_length = j - i + 1;
	if (final_length < 0)
		final_length = 0;
	final = create_final(s1, i, final_length);
	return (final);
}

static	char	*create_final(char const *given, int start, int length)
{
	char	*final;
	int		i;

	i = 0;
	final = malloc(length + 1);
	if (!final)
		return ((void *)0);
	while (i < length && length > 0)
	{
		final[i] = given[start + i];
		i++;
	}
	final[length] = '\0';
	return (final);
}
