/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:47:39 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/08 18:07:48 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*new;

	if (f != NULL && del != NULL)
	{
		final = NULL;
		while (lst != NULL)
		{
			new = ft_lstnew(f(lst->content));
			if (new == NULL)
			{
				ft_lstclear(&final, del);
				break ;
			}
			ft_lstadd_back(&final, new);
			lst = lst->next;
		}
		return (final);
	}
	return (NULL);
}
