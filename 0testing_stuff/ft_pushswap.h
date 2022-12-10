/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:35:26 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/12/08 10:30:22 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_stack
{
	int				pos;
	int				val;
	int				cor;
	int				curr;
	struct s_stack	*next;
}	t_stack;

int			ft_printf(const char *mains, ...);
char		**ft_split(char const *s, char c);
t_stack		*make_stack_a(const char *str);
t_stack		*add_to_stack(t_stack *head, const char *number);
t_stack		*make_empty(t_stack *head);
long long	ft_atou(const char *str);

#endif