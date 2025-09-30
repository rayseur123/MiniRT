/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:37:43 by njooris           #+#    #+#             */
/*   Updated: 2025/09/30 10:43:42 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

#include "../../../includes/scene.h"

t_tuple	position(t_ray ray, double range) // range = time
{
	return (tuple_addition(ray.origin, tuple_multiplication(ray.direction, range)));
}

t_ray	set_ray(const t_tuple point, const t_tuple vector)
{
	t_ray ray;

	ray.origin = point;
	ray.direction = vector;
	return (ray);
}

t_inter	set_intersection(double t, t_obj *obj)
{
	t_inter	inter;

	inter.obj = obj;
	inter.range = t;
	return (inter);
}

int	set_intersections(t_inters *inters, t_inter inter1, t_inter inter2)
{
	inters->count = 2;
	inters->inters[0] = inter1;
	inters->inters[1] = inter2;
	return (0);
}

t_inter	*hit(t_inters *inters)
{
	int			min;
	uint32_t	i;

	min = 0;
	i = 1;
	while (i < inters->count)
	{
		if ((inters->inters[i].range > 0) && 
			(inters->inters[i].range < inters->inters[min].range || 
			inters->inters[min].range < 0))
			min = i;
		i++;
	}
	if (inters->inters[min].range < 0)
		return (NULL);
	return (&inters->inters[min]);
}