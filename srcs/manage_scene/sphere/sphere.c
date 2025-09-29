/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:14:57 by njooris           #+#    #+#             */
/*   Updated: 2025/09/29 15:24:38 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_sphere sphere()
{
	static uint32_t id;
	t_sphere sphere;

	sphere.id = id++;
	return (sphere);
}

t_inter	intersection(double t, t_obj *obj)
{
	t_inter	inter;

	inter.obj = obj;
	inter.range = t;
	return (inter);
}

t_inters	intersections(t_inter inter1, t_inter inter2)
{
	t_inters	inters;

	inters.count = 2;
	inters.inters[0] = inter1;
	inters.inters[1] = inter2;
	return (inters);
}

int	intersect_sphere(t_sphere s, t_ray r, t_inter *inter1, t_inter *inter2)
{
	const t_tuple	sphere_to_ray = tuple_subtraction(r.origin, set_point(0, 0, 0));
	const double 		a = dot_product(r.direction, r.direction);
	const double 		b = 2 * dot_product(r.direction, sphere_to_ray);
	const int		discrim = b * b - 4 * a * dot_product(sphere_to_ray, sphere_to_ray);

	if (discrim < 0)
		return (1);
	inter1->range = (-b - sqrt(discrim) / (2 * a));
	inter2->range = (-b + sqrt(discrim) / (2 * a));
	return (0);
}
