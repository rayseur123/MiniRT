/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:38:18 by njooris           #+#    #+#             */
/*   Updated: 2025/09/23 10:18:21 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "vector.h"

void	*vector_init(size_t element_size, void (*del)(void *))
{
	t_vcthead	*vtchead;

	vtchead = malloc(sizeof (t_vcthead));
	if (!vtchead)
		return (NULL);
	vtchead->capacity = 0;
	vtchead->size = 0;
	vtchead->element_size = element_size;
	vtchead->del = del;
	return (&vtchead->data);
}
