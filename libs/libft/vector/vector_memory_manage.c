/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_memory_manage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:11:52 by njooris           #+#    #+#             */
/*   Updated: 2025/11/19 11:31:22 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdio.h>

t_vcthead	*vector_realloc(t_vcthead *vcthead)
{
	t_vcthead	*new_vcthead;
	size_t		new_capacity;

	if (vcthead->capacity == 0)
		new_capacity = 1;
	else
		new_capacity = 2 * vcthead->capacity;
	new_vcthead = ft_realloc(vcthead,
			sizeof(t_vcthead) + (vcthead->capacity * vcthead->element_size),
			sizeof(t_vcthead) + (new_capacity * vcthead->element_size));
	if (!new_vcthead)
		return (NULL);
	new_vcthead->capacity = new_capacity;
	return (new_vcthead);
}

size_t	vector_alloc(t_vector vector, size_t nb_new_element)
{
	t_vcthead	*new_head;
	t_vcthead	*old_head;
	size_t		new_capacity;

	old_head = get_vector_head(vector);
	new_capacity = nb_new_element + old_head->capacity;
	new_head = ft_realloc(old_head,
			sizeof(t_vcthead) + (old_head->capacity * old_head->size),
			sizeof(t_vcthead) + (new_capacity * old_head->size));
	if (!new_head)
		return (1);
	new_head->capacity = new_capacity;
	vector = (t_vector) & new_head->data;
	return (0);
}
