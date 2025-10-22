/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:59:50 by njooris           #+#    #+#             */
/*   Updated: 2025/10/22 14:06:41 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "color.h"
#include "light.h"
#include "canvas.h"
#include "sphere.h"
#include <math.h>
#include <stdlib.h>

t_inter	*intersect_manage(const t_ray ray, t_obj *obj, t_inters *xs)
{
	intersect(ray, obj, xs);
	return (hit(xs));
}

t_rgb	add_phong(const t_inter *h, const t_tuple point, t_ray ray)
{
	t_tuple		normal;
	t_tuple		eye;
	t_rgb		color;
	t_lighting	l;

	l.light = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	l.mat = h->obj->material;
	normal = normal_at(*h->obj, point);
	eye = tuple_negation(ray.direction);
	color = lighting(l, eye, point, normal);
	return (color);
}

