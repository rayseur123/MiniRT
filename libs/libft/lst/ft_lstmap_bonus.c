/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:04:40 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 10:52:51 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*temp;

	if (!lst)
		return (NULL);
	l = NULL;
	while (lst)
	{
		temp = ft_lstnew(0);
		if (!temp)
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		temp->content = f(lst->content);
		ft_lstadd_back(&l, temp);
		lst = lst->next;
	}
	return (l);
}
