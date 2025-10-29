/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:52:40 by dernst            #+#    #+#             */
/*   Updated: 2025/10/29 15:39:38 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <math.h>
#include "intersection.h"

void	swap_double (double *t0, double *t1)
{
	double	temp;

	temp = *t0;
	*t0 = *t1;
	*t1 = temp;
}

void	trunc_cylinder(t_obj *o, const t_ray r, t_inters *xs, double t0, double t1)
{
	double	y0;
	double	y1;

	if (t0 > t1)
		swap_double(&t0, &t1);
	y0 = r.origin.y + t0 * r.direction.y;
	if (o->min <  y0 && y0 < o->max)
		xs->inters[xs->count++] = set_intersection(t0, o);
	y1 = r.origin.y + t1 * r.direction.y;
	if (o->min < y1 && y1 < o->max)
		xs->inters[xs->count++] = set_intersection(t1, o);
}

bool	check_caps(t_ray r, double t)
{
	double	x;
	double	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	if ((x * x + z * z) <= 1)
		return (true);
	return (false);
}

void	intersect_caps(t_obj *o, const t_ray r, t_inters *xs)
{
	double	t;

	if (!o->closed || r.direction.y == 0.0)
		return;
	t = (o->min - r.origin.y) / r.direction.y;
	if (check_caps(r, t))
		xs->inters[xs->count++] = set_intersection(t, o);
	t = (o->max - r.origin.y) / r.direction.y;
	if (check_caps(r, t))
		xs->inters[xs->count++] = set_intersection(t, o);
}

void	intersect_cylinder(t_obj *o, const t_ray r, t_inters *xs)
{
	double	a;
	double	b;
	double	c;
	double	disc;

	a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	if (a == 0)
		return ;
	b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return ;
	trunc_cylinder(o, r, xs, (-b - sqrt(disc)) / (2 * a), (-b + sqrt(disc)) / (2 * a));
	intersect_caps(o, r ,xs);
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