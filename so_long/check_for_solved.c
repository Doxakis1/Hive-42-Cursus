/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_solved.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 04:34:02 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 05:45:09 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_solved(t_map *my_map, size_t i)
{
	int		collectable;
	int		map_exit;
	int		player;
	size_t	j;

	collectable = 0;
	map_exit = 0;
	player = 0;
	while (++i <= my_map->height)
	{
		j = -1;
		while (++j < my_map->width)
		{
			if (my_map->map[i][j] == 'C')
				collectable++;
			if (my_map->map[i][j] == 'E')
				map_exit++;
		}
	}
	if (collectable == 0 && map_exit == 0)
		move_escape(my_map);
	return ;
}
