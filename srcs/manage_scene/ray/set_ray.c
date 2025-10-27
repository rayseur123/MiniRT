/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:56:34 by dernst            #+#    #+#             */
/*   Updated: 2025/10/27 09:41:44 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "tuple.h"
#include <stdlib.h>

t_ray	set_ray(const t_tuple point, const t_tuple vector)
{
	t_ray	ray;

	ray.origin = point;
	ray.direction = vector;
	return (ray);
}

t_inter	set_intersection(double t, t_obj *obj)
{
	t_inter	inter;

	inter.null = false;
	inter.obj = obj;
	inter.range = t;
	inter.eyev = set_point(0, 0, 0);
	inter.inside = false;
	inter.nb_inter = 0;
	inter.normalv = set_vector(0, 0, 0);
	inter.point = set_point(0, 0, 0);
	return (inter);
}

int	set_intersections(t_inters *inters, t_inter inter1, t_inter inter2)
{
	inters->inters = malloc(sizeof(t_inter) * 2);
	inters->count = 2;
	inters->inters[0] = inter1;
	inters->inters[1] = inter2;
	return (0);
}
