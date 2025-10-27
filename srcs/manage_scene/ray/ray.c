/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:37:43 by njooris           #+#    #+#             */
/*   Updated: 2025/10/16 08:41:21 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "stdlib.h"
#include "sphere.h"
#include <math.h>

t_tuple	position(t_ray ray, double range)
{
	return (tuple_addition(ray.origin,
			tuple_multiplication(ray.direction, range)));
}

t_inter	*hit(t_inters *inters)
{
	unsigned int	min;
	unsigned int	i;

	min = 0;
	i = 1;
	if (inters->count <= 0)
		return (NULL);
	while (i < inters->count)
	{
		if ((inters->inters->null == false && inters->inters[min].range < 0)
			|| (inters->inters[i].range >= 0
				&& inters->inters[i].range < inters->inters[min].range))
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

void	shape_intersect(t_obj *o, t_ray r, t_inters *xs)
{
	double	t;

	if (o->type == PLANE)
	{
		if (fabs(r.direction.y) < EPSILON)
		{
			xs->inters[xs->count].null = true;
			return ;
		}
		t = -r.origin.y / r.direction.y;
		xs->inters[xs->count++] = set_intersection(t, o);
	}
	else if (o->type == SPHERE)
		intersect_sphere(o, r, xs);
}

void	intersect(t_ray r, t_obj *o, t_inters *xs)
{
	r = transform(r, o->inverse_transform);
	if (o->type == SPHERE)
		intersect_sphere(o, r, xs);
}
