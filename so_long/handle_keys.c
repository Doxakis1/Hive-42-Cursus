/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:14:32 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 04:26:57 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keys(int pressed_key, t_map *my_map)
{
	if (!my_map)
		return (0);
	if (pressed_key == 0)
		move_left(my_map);
	if (pressed_key == 1)
		move_down(my_map);
	if (pressed_key == 2)
		move_right(my_map);
	if (pressed_key == 13)
		move_up(my_map);
	if (pressed_key == 53)
		move_escape(my_map);
	draw_the_window(my_map, -1, -1);
	return (0);
}

void	move_right(t_map *my_map)
{
	if (my_map->player_x + 1 >= my_map->width)
		return ;
	if (my_map->map[my_map->player_y][my_map->player_x + 1] != '1')
	{
		if (my_map->player_x == my_map->exit_x && my_map->player_y
			== my_map->exit_y)
		{
			my_map->map[my_map->player_y][my_map->player_x + 1] = 'P';
			my_map->map[my_map->player_y][my_map->player_x] = 'E';
		}
		else
		{
			my_map->map[my_map->player_y][my_map->player_x + 1] = 'P';
			my_map->map[my_map->player_y][my_map->player_x] = '0';
		}
		ft_printf("Moves made:%d\n", ++(my_map->move_counter));
	}
	return ;
}

void	move_left(t_map *my_map)
{
	if (my_map->player_x - 1 < 0)
		return ;
	if (my_map->map[my_map->player_y][my_map->player_x - 1] != '1')
	{
		if (my_map->player_x == my_map->exit_x && my_map->player_y
			== my_map->exit_y)
		{
			my_map->map[my_map->player_y][my_map->player_x - 1] = 'P';
			my_map->map[my_map->player_y][my_map->player_x] = 'E';
		}
		else
		{
			my_map->map[my_map->player_y][my_map->player_x - 1] = 'P';
			my_map->map[my_map->player_y][my_map->player_x] = '0';
		}
		ft_printf("Moves made:%d\n", ++(my_map->move_counter));
	}
	return ;
}

void	move_up(t_map *my_map)
{
	if (my_map->player_y - 1 < 0)
		return ;
	if (my_map->map[my_map->player_y - 1][my_map->player_x] != '1')
	{
		if (my_map->player_x == my_map->exit_x && my_map->player_y
			== my_map->exit_y)
		{
			my_map->map[my_map->player_y - 1][my_map->player_x] = 'P';
			my_map->map[my_map->player_y][my_map->player_x] = 'E';
		}
		else
		{
			my_map->map[my_map->player_y - 1][my_map->player_x] = 'P';
			my_map->map[my_map->player_y][my_map->player_x] = '0';
		}
		ft_printf("Moves made:%d\n", ++(my_map->move_counter));
	}
	return ;
}

void	move_down(t_map *my_map)
{
	if (my_map->player_y + 1 > my_map->height)
		return ;
	if (my_map->map[my_map->player_y + 1][my_map->player_x] != '1')
	{
		if (my_map->player_x == my_map->exit_x && my_map->player_y
			== my_map->exit_y)
		{
			my_map->map[my_map->player_y + 1][my_map->player_x] = 'P';
			my_map->map[my_map->player_y][my_map->player_x] = 'E';
		}
		else
		{
			my_map->map[my_map->player_y + 1][my_map->player_x] = 'P';
			my_map->map[my_map->player_y][my_map->player_x] = '0';
		}
		ft_printf("Moves made:%d\n", ++(my_map->move_counter));
	}
	return ;
}
