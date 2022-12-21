/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_from_one_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:31:38 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/21 02:04:10 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	make_from_one_string(char **str, const char *given, t_stack **head)
{
	int	i;
	int k;

	k = 0;
	i = 0;
	if (str)
		free (str);
	str = ft_split(given, ' ');
	while (str[i])
	{
		if (!(add_to_stack(head, str[i++])))
		{
			// while(str[k])
			// 	free(str[k++]);
			return (0);
		}
		free(str[i - 1]);
		str[i - 1] = NULL;
	}
	if (str[i])
		free(str[i]);
	return (1);
}