/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:09:18 by njooris           #+#    #+#             */
/*   Updated: 2025/11/19 11:27:12 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdio.h>

void	*vector_next(t_vector vct)
{
	t_vcthead	*head;
	t_vector	*vector;

	vector = (t_vector *)vct;
	head = get_vector_head(*vector);
	if (head->capacity == head->size)
	{
		head = vector_realloc(head);
		if (!head)
			return (NULL);
		*vector = &head->data;
	}
	return (&head->data[head->element_size * head->size++]);
}

size_t	vector_add(t_vector vct, void *element)
{
	t_vector	*vector;
	t_vector	*next;

	vector = (t_vector *)vct;
	if (!element)
		return (1);
	next = vector_next(vector);
	if (!next)
		return (1);
	ft_memcpy(next, element, get_vector_head(*vector)->element_size);
	return (0);
}
