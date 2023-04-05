/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_escape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 04:20:18 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 04:32:07 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_escape(t_map *my_map)
{
	mlx_destroy_image(my_map->mlx, my_map->wall);
	mlx_destroy_image(my_map->mlx, my_map->walkable);
	mlx_destroy_image(my_map->mlx, my_map->collectable);
	mlx_destroy_image(my_map->mlx, my_map->player);
	mlx_destroy_image(my_map->mlx, my_map->exit);
	mlx_destroy_window(my_map->mlx, my_map->win);
	exit(0);
}
