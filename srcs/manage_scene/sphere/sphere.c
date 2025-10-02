/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:14:57 by njooris           #+#    #+#             */
/*   Updated: 2025/10/02 13:48:28 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "../../../includes/scene.h"
#include <math.h>

t_obj	sphere(void)
{
	static int32_t	id;
	t_obj			obj;

	obj.id = id++;
	obj.type = SPHERE;
	set_identity_matrix(obj.transform);
	return (obj);
}

uint32_t	intersect_sphere(t_obj *s, t_ray r, t_inters *inters)
{
	const t_tuple		sphere_to_ray = tuple_subtraction(r.origin,
			set_point(0, 0, 0));
	const double		a = dot_product(r.direction, r.direction);
	const double		b = 2 * dot_product(r.direction, sphere_to_ray);
	const double		c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	const long int		discriminant = (b * b) - 4 * a * c;

	(void)s;
	inters->count = 0;
	if (discriminant < 0)
		return (1);
	inters->count = 2;
	inters->inters[0] = set_intersection((-b - sqrt(discriminant))
			/ (2 * a), s);
	inters->inters[1] = set_intersection((-b + sqrt(discriminant))
			/ (2 * a), s);
	return (0);
}

void	set_transform(t_obj *s, t_matrix4 m)
{
	matrix4_cpy(s->transform, m);
}

void	do_draw_sphere(t_canvas canvas, double wall_size,
			t_rgb color, t_obj *obj)
{
	u_int32_t	x;
	u_int32_t	y;
	double		half;
	t_inters	xs;
	t_ray		ray;
	t_p_light	p_light;
	t_tuple		point;
	t_tuple		normal;
	t_tuple		eye;
	t_inter		*h;

	p_light	= point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	half = wall_size / 2;
	ray.origin = set_point(0, 0, -5);
	x = -1;
	while (++x < WIDTH_CANVA)
	{
		y = -1;
		while (++y < HEIGHT_CANVA)
		{
			ray.direction = tuple_normalization(tuple_subtraction(
						set_point(-half + (wall_size / WIDTH_CANVA) * x,
							half - (wall_size / WIDTH_CANVA) * y, 10),
						ray.origin));
			intersect(ray, obj, &xs);
			h = hit(&xs);
			if (h)
			{
				point = position(ray, h->range);
				normal = normal_at(*h->obj, point);
				eye = tuple_negation(ray.direction);
				color = lighting(h->obj->material, p_light, point, eye, normal);
				put_px_in_canva(canvas, x, y, color);
			}
		}
	}
}

void	draw_sphere(t_canvas canvas)
{
	t_obj		obj;
	double		wall_size;

	wall_size = 10;
	obj = sphere();
	obj.material = material();
	obj.material.color = set_rgb(200, 50, 200);
	do_draw_sphere(canvas, wall_size, set_rgb(255, 0, 0), &obj);
}
