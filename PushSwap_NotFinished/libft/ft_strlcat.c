/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:16:01 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/08 11:40:45 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	source_length;
	size_t	destination_length;

	source_length = ft_strlen(src);
	if (size == 0)
		return (source_length);
	destination_length = ft_strlen(dst);
	if (size <= destination_length)
		return (source_length + size);
	while (size-- > (destination_length + 1) && *src != '\0')
		*(dst++ + destination_length) = *(src++);
	*(dst + destination_length) = '\0';
	return (destination_length + source_length);
}
