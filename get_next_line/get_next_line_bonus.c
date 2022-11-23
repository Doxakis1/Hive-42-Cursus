/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:27:19 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/23 14:15:23 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static char	*k[1024] = {0};
	int			a;
	char		*gnl;
	char		*b;
	int			i;

	i = 1;
	gnl = NULL;
	b = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (b && i > 0 && fd >= 0 && BUFFER_SIZE > 0 && read(fd, 0, 0) >= 0)
	{
		i = read(fd, b, BUFFER_SIZE);
		b[i] = '\0';
		a = join(&k[fd], k[fd], b, 0);
		if (ft_checklast(k[fd]) || i == 0)
		{
			a = join(&gnl, k[fd], 0, -1);
			a = join(&k[fd], &k[fd][a], 0, 0);
			break ;
		}
	}
	if (b)
		free(b);
	return (gnl);
}
