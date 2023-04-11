/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:47:39 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/11 08:26:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*new;

	if (f != (void *)0 && del != (void *)0)
	{
		final = (void *)0;
		while (lst != (void *)0)
		{
			new = ft_lstnew(f(lst->content));
			if (new == (void *)0)
			{
				ft_lstclear(&final, del);
				break ;
			}
			ft_lstadd_back(&final, new);
			lst = lst->next;
		}
		return (final);
	}
	return ((void *)0);
}
