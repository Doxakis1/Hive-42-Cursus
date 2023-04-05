/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:57:40 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 05:31:58 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_test(char *str)
{
	size_t	size_of_map_name;

	size_of_map_name = ft_strlen(str);
	if (size_of_map_name <= 4)
		exit(ft_printf("Error\nMap name is incorrect!\n"));
	if (str[size_of_map_name - 4] != '.' || str[size_of_map_name - 3] != 'b' \
	|| str[size_of_map_name - 2] != 'e' || str[size_of_map_name - 1] != 'r')
		exit(ft_printf("Error\nMap name is incorrect!\n"));
	return (0);
}
