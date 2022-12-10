/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:33:54 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/17 13:42:13 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*final;
	size_t	calculated;

	calculated = count * size;
	final = (void *)malloc(calculated);
	if (final)
		ft_bzero(final, calculated);
	return (final);
}
