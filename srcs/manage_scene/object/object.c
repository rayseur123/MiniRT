/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:52:40 by dernst            #+#    #+#             */
/*   Updated: 2025/10/30 12:49:34 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <math.h>
#include "intersection.h"

void	intersect_cylinder(t_obj *o, const t_ray r, t_inters *xs)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	t_range	range;

	a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	if (a == 0)
		return ;
	b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return ;
	range.t0 = (-b - sqrt(disc)) / (2 * a);
	range.t1 = (-b + sqrt(disc)) / (2 * a);
	trunc_cylinder(o, r, xs, range);
	intersect_caps(o, r, xs);
}

void	intersect_plane(t_obj *o, const t_ray r, t_inters *xs)
{
	double	t;

	if (fabs(r.direction.y) < EPSILON)
		return ;
	t = -r.origin.y / r.direction.y;
	xs->inters[xs->count++] = set_intersection(t, o);
}

uint32_t	intersect_sphere(t_obj *s, const t_ray r, t_inters *inters)
{
	const t_tuple		sphere_to_ray = tuple_subtraction(r.origin,
			set_point(0, 0, 0));
	const double		a = dot_product(r.direction, r.direction);
	const double		b = 2 * dot_product(r.direction, sphere_to_ray);
	const double		c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	const double		disc = (b * b) - 4 * a * c;

	if (disc < 0)
		return (1);
	inters->inters[inters->count++] = set_intersection((-b - sqrt(disc))
			/ (2 * a), s);
	inters->inters[inters->count++] = set_intersection((-b + sqrt(disc))
			/ (2 * a), s);
	return (0);
}
