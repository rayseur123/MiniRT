/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:25:11 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 10:50:40 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;

	l = NULL;
	if (lst && *lst)
	{
		while ((*lst)->next)
		{
			l = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = l;
		}
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
