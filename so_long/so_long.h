/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:17:27 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 04:39:48 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf.h"
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map{
	void		*mlx;
	void		*win;
	void		*wall;
	void		*player;
	void		*collectable;
	void		*walkable;
	void		*exit;
	int			act;
	size_t		height;
	size_t		width;
	size_t		exit_x;
	size_t		exit_y;
	size_t		player_x;
	size_t		player_y;
	int			move_counter;
	char		map[800][800];
}	t_map;

int		ft_printf(const char *mains, ...);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *a, size_t b);
int		map_test(char *str);
int		read_map(char *name, char map[800][800], size_t *map_height,
			size_t *map_width);
int		check_map(char map[800][800], size_t *map_height, size_t *map_width);
int		check_valid_chars(char *s);
int		check_borders(char map[800][800], size_t *map_height,
			size_t *map_width);
int		check_enough(char map[800][800], size_t *map_height, size_t *map_width,
			size_t i);
int		check_solvable(char map[800][800], size_t *map_height,
			size_t *map_width);
int		check_solvable_helper(char map[800][800], size_t *max_height,
			size_t map_height, size_t map_width);
int		check_valid_chars2(char *s);
int		handle_keys(int pressed_key, t_map *my_map);
void	draw_the_window(t_map *my_map, size_t i, size_t j);
void	move_left(t_map *my_map);
void	move_right(t_map *my_map);
void	move_up(t_map *my_map);
void	move_down(t_map *my_map);
int		p_loc(t_map *my_map, size_t i, size_t j);
int		e_loc(t_map *my_map, size_t i, size_t j);
int		move_escape(t_map *my_map);
void	check_for_solved(t_map *my_map, size_t i);
#endif