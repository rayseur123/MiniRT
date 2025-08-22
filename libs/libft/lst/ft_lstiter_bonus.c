/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:26:47 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 10:52:13 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*l;

	l = NULL;
	if (lst)
	{
		while (lst->next)
		{
			l = lst->next;
			f(lst->content);
			lst = l;
		}
		f(lst->content);
	}
}
