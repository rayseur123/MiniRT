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
#include "../../../includes/scene.h"
#include <math.h>

t_sphere sphere(void)
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

u_int32_t intersect_sphere(t_sphere s, t_ray r, t_inters *inters)
{
	(void)s;
	const t_tuple	sphere_to_ray = tuple_subtraction(r.origin, set_point(0, 0, 0));
	const double 		a = dot_product(r.direction, r.direction);
	const double 		b = 2 * dot_product(r.direction, sphere_to_ray);
	const int		discriminant = b * b - 4 * a * (dot_product(sphere_to_ray, sphere_to_ray) - 1);

	inters->count = 0;
	if (discriminant < 0)
		return (1);
	inters->count = 2;
	inters->inters[0].range = -b - sqrt(discriminant) / (2 * a);
	inters->inters[1].range = -b + sqrt(discriminant) / (2 * a);

	// inters->inters[0].range =  42;
	// inters->inters[1].range = 16;
	return (0);
}

// void	draw_sphere(t_canvas canvas)
// {
// 	int x;
// 	int y;
// 	t_rgb color;
// 	t_sphere s;
// 	t_tuple pos;
// 	t_ray r;
// 	t_tuple ray_origin;
// 	pos = set_point(0, 0, 0);
//
// 	x = 0;
// 	y = 0;
// 	ray_origin = set_point(0,0,0);
// 	r.direction = ray_origin;
// 	r.origin = tuple_normalization(tuple_subtraction(pos, ray_origin));
// 	s = sphere();
// 	color = set_rgb(127, 0, 0);
// 	while (x < WIDTH_CANVA) {
// 		while (y < HEIGHT_CANVA) {
// 			pos = set_point(x, y , 0);
// 			if (intersect_sphere(s, r) > 0){
// 				put_px_in_canva(canvas, x, y , color);
// 			}
// 			y++;
// 		}
// 		y = 0;
// 		x++;
// 	}
// }
