/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_from_one_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:31:38 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/14 17:38:16 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	make_from_one_string(char **str, const char *given, t_stack **head)
{
	int	i;

	i = 0;
	str = ft_split(given, ' ');
	while (str[i])
		if (!(add_to_stack(head, str[i++])))
			return (0);
	return (1);
}