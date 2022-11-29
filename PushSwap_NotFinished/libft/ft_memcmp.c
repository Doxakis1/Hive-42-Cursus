/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:20:37 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/08 14:55:01 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *) s1;
	m2 = (unsigned char *) s2;
	while (n-- > 0)
		if (*(m1++) != *(m2++))
			break ;
	return (*(--m1) - *(--m2));
}
