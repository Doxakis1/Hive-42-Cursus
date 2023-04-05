/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:35:37 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 02:58:44 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *name, char map[800][800], size_t *map_height,
	size_t *map_width)
{
	int		fd;
	int		read_char;
	char	reading[1];

	read_char = 1;
	fd = open(name, O_RDONLY);
	if (fd < 0 || read(fd, reading, 1) < 1)
		exit(ft_printf("Error\nNo map with that name exist\n"));
	while (read_char)
	{
		map[*map_height][*map_width] = reading[0];
		if (reading[0] == '\n')
		{
			map[*map_height][*map_width] = '\0';
			*map_width = -1;
			*map_height += 1;
		}
		*map_width += 1;
		if (*map_width == 802 || *map_height == 802)
			exit(ft_printf("Error\nInvalid map\n"));
		read_char = read(fd, reading, 1);
	}
	map[*map_height][*map_width] = '\0';
	close(fd);
	return (0);
}
