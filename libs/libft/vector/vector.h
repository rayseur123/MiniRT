/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:08:24 by njooris           #+#    #+#             */
/*   Updated: 2025/11/19 11:26:17 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdint.h>

typedef void	*t_vector;

typedef struct s_vcthead
{
	size_t	element_size;
	size_t	size;
	size_t	capacity;
	void	(*del)(void *);
	uint8_t	data[];
}	t_vcthead;

t_vcthead	*get_vector_head(t_vector vector);
size_t		vector_get_size_used(t_vector vector);
size_t		vector_get_capacity(t_vector vector);
t_vector	vector_init(size_t element_size, void (*del)(void *));
t_vcthead	*vector_realloc(t_vcthead *vcthead);
size_t		vector_alloc(t_vector vector, size_t nb_new_element);
size_t		vector_add(t_vector vector, void *element);
void		delete_vector(t_vector vector);
void		free_vector(t_vector vector);

#endif