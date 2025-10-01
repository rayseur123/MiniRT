/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:37:43 by njooris           #+#    #+#             */
/*   Updated: 2025/09/30 13:36:47 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

#include "../../../includes/scene.h"

t_tuple	position(t_ray ray, double range) // range = time
{
	return (tuple_addition(ray.origin,
			tuple_multiplication(ray.direction, range)));
}

t_inter	*hit(t_inters *inters)
{
	int			min;
	uint32_t	i;

	min = 0;
	i = 1;
	while (i < inters->count)
	{
		if ((inters->inters[i].range > 0)
			&& (inters->inters[i].range < inters->inters[min].range
				|| inters->inters[min].range < 0))
			min = i;
		i++;
	}
	if (inters->inters[min].range < 0)
		return (NULL);
	return (&inters->inters[min]);
}

t_ray	transform(t_ray ray, t_matrix4 m)
{
	t_ray	new_ray;

	new_ray.direction = matrix4_multiplication_by_tuple(m, ray.direction);
	new_ray.origin = matrix4_multiplication_by_tuple(m, ray.origin);
	return (new_ray);
}

void	intersect(t_ray r, t_obj *o, t_inters *xs)
{
	r = transform(r, matrix4_inverse(o->transform, o->reverse_transform));
	if (o->type == SPHERE)
		intersect_sphere(o, r, xs);
}
