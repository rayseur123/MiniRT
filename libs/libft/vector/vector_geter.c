/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_geter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:35:16 by njooris           #+#    #+#             */
/*   Updated: 2025/09/01 16:37:24 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vcthead	*get_vector_head(t_vector vector)
{
	return (&((t_vcthead *)vector)[-1]);
}

size_t	vector_get_size_used(t_vector vector)
{
	return (get_vector_head(vector)->size);
}

size_t	vector_get_capacity(t_vector vector)
{
	return (get_vector_head(vector)->capacity);
}
