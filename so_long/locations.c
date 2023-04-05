/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:49:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 04:31:57 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p_loc(t_map *my_map, size_t i, size_t j)
{
	my_map->player_x = j;
	my_map->player_y = i;
	return (1);
}

int	e_loc(t_map *my_map, size_t i, size_t j)
{
	my_map->exit_x = j;
	my_map->exit_y = i;
	return (1);
}
