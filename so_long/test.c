/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:19:28 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/21 18:30:05 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_new_window(mlx, 920, 80, "Hello world!");
	mlx_loop(mlx);
	//mlx_mouse_hide();
}
