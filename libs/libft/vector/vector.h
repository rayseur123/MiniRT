/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:08:24 by njooris           #+#    #+#             */
/*   Updated: 2025/09/02 11:57:22 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#ifndef VECTOR_H
# define VECTOR_H

typedef	void	*t_vector;

typedef struct s_vcthead
{
	size_t	element_size; // size of an element
	size_t	size; // size used
	size_t	capacity; // size max
	void	(*del)(void *);
	uint8_t	data[];
}	t_vcthead;

t_vcthead	*get_vector_head(t_vector vector);
size_t		vector_get_size_used(t_vector vector);
size_t		vector_get_capacity(t_vector vector);


t_vector	vector_init(size_t element_size, void (*del)(void *));

t_vcthead	*vector_realloc(t_vcthead *vcthead);
size_t 		vector_alloc(t_vector vector, size_t nb_new_element);
size_t		vector_add(t_vector vector, void *element);

void		delete_vector(t_vector vector);
void		free_vector(t_vector vector);

#endif