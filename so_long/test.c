/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:19:28 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/23 20:44:56 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main(void)
{
	void	*mlx; //We create a pointer to our window initialization
	void	*mlx_win; //We create a pointer to the window that our program will be using
	int		x;
	int		y;
	int		o;
	int		m;
	int		p;
	char	*hive = "HIVE";

	x = 0;
	y = 0;
	mlx = mlx_init(); //We initialized mlx and stored its address to "mlx"

	
	mlx_win = mlx_new_window(mlx, 42*42, 42*42, "Tewsting time!"); 
	//We initialized our window and stored its address to "mlx_win"
	
	while (x <= 42*42)
	{
		y = 0;
		while (y <= 42*42)
		{
			o = x % (hive[y%4]);
			m = y % (hive[x%4]);
			p = (x * y * 42424242);
			if(o == 42 && m == 2)
				mlx_string_put(mlx, mlx_win, x, y, p, "42");
			if(o == 4 && m == 42)
				mlx_string_put(mlx, mlx_win, x, y, p, "24");
			// if(o != 4 && m != 2)
			// 	mlx_string_put(mlx, mlx_win, x, y, p, " 42 ");
			if(o == 4 && m == 2)
				mlx_string_put(mlx, mlx_win, x, y, p, "42");
			if(o == 2 && m == 4)
				mlx_string_put(mlx, mlx_win, x, y, p, "24");
			// if(o == 4 && m == 4)
			// 	mlx_string_put(mlx, mlx_win, x, y, p, " 42 ");
			// if(o == 2 && m == 2)
			// 	mlx_string_put(mlx, mlx_win, x, y, p, " 42 ");
			// if(o == 4 )
			// 	mlx_string_put(mlx, mlx_win, x, y, p, " 42 ");
			// // if(m == 4 )
			// // 	mlx_pixel_put(mlx, mlx_win, x, y, p);
			// // if(o == 2 )
			// // 	mlx_pixel_put(mlx, mlx_win, x, y, p);
			// if(m == 4 )
			// 	mlx_string_put(mlx, mlx_win, x, y, p, " 42 ");
			// if(o == 4 )
			// 	mlx_string_put(mlx, mlx_win, x, y, p, " 42 ");
			// // if(m == 4 )
			// // 	mlx_pixel_put(mlx, mlx_win, x, y, p);
			// // if(o == 2 )
			// // 	mlx_pixel_put(mlx, mlx_win, x, y, p);
			// if(m == 4 )
			// 	mlx_string_put(mlx, mlx_win, x, y, p, " 42 ");
			y++;
		}
		x++;
	}
	
		
	//mlx_pixel_put(mlx, mlx_win, (690/2 +1), (420/2 + 1), 0xFFFFFF);
	
	mlx_loop(mlx); //we start the window loop
	
	return (0);
}
