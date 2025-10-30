/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:42:54 by dernst            #+#    #+#             */
/*   Updated: 2025/10/30 12:49:43 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	swap_double(double *t0, double *t1)
{
	double	temp;

	temp = *t0;
	*t0 = *t1;
	*t1 = temp;
}

void	trunc_cylinder(t_obj *o, t_ray r, t_inters *xs, t_range range)
{
	double	y0;
	double	y1;

	if (range.t0 > range.t1)
		swap_double(&range.t0, &range.t1);
	y0 = r.origin.y + range.t0 * r.direction.y;
	if (o->min < y0 && y0 < o->max)
		xs->inters[xs->count++] = set_intersection(range.t0, o);
	y1 = r.origin.y + range.t1 * r.direction.y;
	if (o->min < y1 && y1 < o->max)
		xs->inters[xs->count++] = set_intersection(range.t1, o);
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
		return ;
	t = (o->min - r.origin.y) / r.direction.y;
	if (check_caps(r, t))
		xs->inters[xs->count++] = set_intersection(t, o);
	t = (o->max - r.origin.y) / r.direction.y;
	if (check_caps(r, t))
		xs->inters[xs->count++] = set_intersection(t, o);
}
