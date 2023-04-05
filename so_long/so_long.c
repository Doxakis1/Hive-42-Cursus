/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:19:46 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 05:44:48 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_the_window(t_map *my_map, size_t i, size_t j)
{
	i = -1;
	while (++i <= my_map->height)
	{
		j = -1 ;
		while (++j < my_map->width)
		{
			if (my_map->map[i][j] == '1' )
				mlx_put_image_to_window(my_map->mlx, my_map->win,
					my_map->wall, j * 30, i * 30);
			if (my_map->map[i][j] == 'E' )
				my_map->act = mlx_put_image_to_window(my_map->mlx, my_map->win,
						my_map->exit, j * 30, i * 30) + e_loc(my_map, i, j);
			if (my_map->map[i][j] == 'P' )
				my_map->act = mlx_put_image_to_window(my_map->mlx, my_map->win,
						my_map->player, j * 30, i * 30) + p_loc(my_map, i, j);
			if (my_map->map[i][j] == 'C' )
				mlx_put_image_to_window(my_map->mlx, my_map->win,
					my_map->collectable, j * 30, i * 30);
			if (my_map->map[i][j] == '0' )
				mlx_put_image_to_window(my_map->mlx, my_map->win,
					my_map->walkable, j * 30, i * 30);
			check_for_solved(my_map, -1);
		}
	}
}

void	open_images(t_map *my_map)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	my_map->wall = mlx_xpm_file_to_image(my_map->mlx, "wall", &width, &height);
	my_map->walkable = mlx_xpm_file_to_image(my_map->mlx, "walkable",
			&width, &height);
	my_map->collectable = mlx_xpm_file_to_image(my_map->mlx,
			"collectable", &width, &height);
	my_map->player = mlx_xpm_file_to_image(my_map->mlx,
			"player", &width, &height);
	my_map->exit = mlx_xpm_file_to_image(my_map->mlx, "exit", &width, &height);
}

void	open_window(t_map *my_map)
{
	my_map->win = mlx_new_window(my_map->mlx, (int)my_map->width * 30,
			(int)my_map->height * 30, "SO_LONG BY MKARATZI");
	open_images(my_map);
	draw_the_window(my_map, 0, 0);
}

int	main(int ac, char **av)
{
	t_map	my_map;

	ft_bzero(&my_map, sizeof(t_map));
	if (ac != 2)
		exit(ft_printf("Error\nWrong amount of parameters given!\n"));
	map_test(av[1]);
	read_map(av[1], my_map.map, &my_map.height, &my_map.width);
	check_map(my_map.map, &my_map.height, &my_map.width);
	my_map.width = 0;
	my_map.height = 0;
	read_map(av[1], my_map.map, &my_map.height, &my_map.width);
	ft_printf("Map reading was successfull!\n");
	my_map.height++;
	my_map.mlx = mlx_init();
	if (!my_map.mlx)
		return (0);
	open_window(&my_map);
	mlx_key_hook(my_map.win, handle_keys, (void *)&my_map);
	mlx_hook(my_map.win, 17, 0, move_escape, (void *)&my_map);
	mlx_loop(my_map.mlx);
	return (0);
}
