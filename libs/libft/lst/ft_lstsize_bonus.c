/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:43:04 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 10:58:00 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*lst2;

	count = 0;
	if (lst)
	{
		count = 1;
		lst2 = lst;
		while (lst2->next != NULL)
		{
			lst2 = lst2->next;
			count++;
		}
	}
	return (count);
}
