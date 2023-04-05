/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solvable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:29:55 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 05:54:27 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_solvable(char map[800][800], size_t *map_height, size_t *map_width)
{
	size_t	i;
	size_t	j;
	int		trials;

	trials = 1;
	while (trials)
	{
		i = 0;
		trials = 0;
		while (i <= *map_height)
		{
			j = -1;
			while (++j < *map_width)
				if (map[i][j] == 'P' || map[i][j] == 'V')
					if (check_solvable_helper(map, map_height, i, j) != 0)
						trials = 1;
			i++;
		}
	}
	i = -1;
	while (++i <= *map_height)
		if (!check_valid_chars2(map[i]))
			return (0);
	return (1);
}

int	check_solvable_helper(char map[800][800], size_t *max_height,
	size_t map_height, size_t map_width)
{
	if (map_height - 1 >= 0 && map[map_height - 1][map_width]
		!= '1' && map[map_height - 1][map_width] != 'V')
	{
		map[map_height - 1][map_width] = 'V';
		return (1);
	}
	if (map_height + 1 <= *max_height && map[map_height + 1][map_width]
		!= '1' && map[map_height + 1][map_width] != 'V')
	{
		map[map_height + 1][map_width] = 'V';
		return (1);
	}
	if (map_width - 1 >= 0 && map[map_height][map_width - 1]
		!= '1' && map[map_height][map_width - 1] != 'V')
	{
		map[map_height][map_width - 1] = 'V';
		return (1);
	}
	if (map[map_height][map_width + 1] != '1' && map[map_height][map_width + 1]
		!= 'V' && map[map_height][map_width + 1] != '\0')
	{
		map[map_height][map_width + 1] = 'V';
		return (1);
	}
	return (0);
}

int	check_valid_chars2(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'E' || s[i] == 'C')
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_chars(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'C'
			&& s[i] != 'E' && s[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}
