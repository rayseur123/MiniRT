/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:59:37 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/23 15:52:50 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetprev(t_list *first, t_list *actual)
{
    t_list	*temp;

    if (first == NULL || actual == NULL || first == actual)
        return (NULL);
    temp = first;
    while (temp->next)
    {
        if (temp->next == actual)
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}
