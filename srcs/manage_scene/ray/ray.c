/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:37:43 by njooris           #+#    #+#             */
/*   Updated: 2025/11/12 17:34:29 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "stdlib.h"
#include <math.h>
#include "shape.h"

t_tuple	position(t_ray ray, double range)
{
	return (tuple_addition(ray.origin,
			tuple_multiplication(ray.direction, range)));
}

t_inter	*hit(t_linter *inters)
{
	t_inter	*min;
	int		i;

	min = NULL;
	i = -1;
	while (++i < inters->count)
	{
		if (inters->inters[i].range < 0)
			continue ;
		if (min == NULL || inters->inters[i].range < min->range)
			min = inters->inters + i;
	}
	return (min);
}

void	shape_intersect(t_obj *o, const t_ray r, t_linter *xs)
{
	if (o->type == PLANE)
		intersect_plane(o, r, xs);
	else if (o->type == SPHERE)
		intersect_sphere(o, r, xs);
	else if (o->type == CYLINDER)
		intersect_cylinder(o, r, xs);
}

t_ray	transform(t_ray ray, t_matrix4 m)
{
	t_ray	new_ray;

	new_ray.direction = matrix4_multiplication_by_tuple(m, ray.direction);
	new_ray.origin = matrix4_multiplication_by_tuple(m, ray.origin);
	return (new_ray);
}

void	intersect(t_ray r, t_obj *o, t_linter *xs)
{
	r = transform(r, o->inverse_transform);
	shape_intersect(o, r, xs);
}
