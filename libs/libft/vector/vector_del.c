/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:36:19 by njooris           #+#    #+#             */
/*   Updated: 2025/11/19 11:27:32 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void	free_vector(t_vector vector)
{
	free(get_vector_head(vector));
}

void	delete_vector(t_vector vector)
{
	t_vcthead	*head;
	size_t		i;

	head = get_vector_head(vector);
	i = 0;
	while (i < head->size && head->del)
	{
		head->del(head->data + (i * head->element_size));
		i++;
	}
	free_vector(vector);
}
