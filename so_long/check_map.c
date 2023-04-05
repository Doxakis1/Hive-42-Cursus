/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:55:18 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 05:58:58 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char map[800][800], size_t *map_height, size_t *map_width)
{
	size_t	i;

	i = 0;
	*map_width = ft_strlen(map[0]);
	while (i <= *map_height)
	{
		if (ft_strlen(map[i]) != *map_width || *map_height < 2
			|| !check_valid_chars(map[i]))
			exit(ft_printf("Error\nMap failed to pass valid map criteria!\n"));
			i++;
	}
	if (!check_borders(map, map_height, map_width)
		|| !check_enough(map, map_height, map_width, -1)
		|| !check_solvable(map, map_height, map_width))
		exit(ft_printf("Error\nMap failed to pass valid map criteria!\n"));
	return (0);
}

int	check_enough(char map[800][800], size_t *map_height, size_t *map_width,
	size_t i)
{
	int		collectable;
	int		map_exit;
	int		player;
	size_t	j;

	collectable = 0;
	map_exit = 0;
	player = 0;
	while (++i <= *map_height)
	{
		j = -1;
		while (++j < *map_width)
		{
			if (map[i][j] == 'C')
				collectable++;
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'E')
				map_exit++;
		}
	}
	if (collectable < 1 || map_exit != 1 || player != 1)
		return (0);
	return (1);
}

int	check_borders(char map[800][800], size_t *map_height, size_t *map_width)
{
	size_t	i;

	i = -1;
	while (++i < *map_width)
		if (map[0][i] != '1' || map[*map_height][i] != '1')
			return (0);
	i = -1;
	while (++i <= *map_height)
	{
		if (map[i][0] != '1' || map[i][*map_width - 1] != '1')
			return (0);
	}
	return (1);
}
