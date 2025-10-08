/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:14:57 by njooris           #+#    #+#             */
/*   Updated: 2025/10/08 13:12:50 by dernst           ###   ########.fr       */
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
	obj.material = material();
	set_identity_matrix(obj.transform);
	return (obj);
}

uint32_t	intersect_sphere(t_obj *s, t_ray r, t_inters *inters)
{
	const t_tuple		sphere_to_ray = tuple_subtraction(r.origin,
			set_point(-1, 1, 1));
	const double		a = dot_product(r.direction, r.direction);
	const double		b = 2 * dot_product(r.direction, sphere_to_ray);
	const double		c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	const double		discriminant = (b * b) - 4 * a * c;

	if (discriminant < 0)
		return (1);
	inters->inters[inters->count++] = set_intersection((-b - sqrt(discriminant))
			/ (2 * a), s);
	inters->inters[inters->count++] = set_intersection((-b + sqrt(discriminant))
			/ (2 * a), s);
	return (0);
}

void	set_transform(t_obj *s, t_matrix4 m)
{
	matrix4_cpy(s->transform, m);
}

t_rgb	add_phong(const t_inter *h, const t_tuple point, t_ray ray)
{
	t_light	light;
	t_tuple	normal;
	t_tuple	eye;
	t_rgb	color;

	light = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	normal = normal_at(*h->obj, point);
	eye = tuple_negation(ray.direction);
	color = lighting(h->obj->material, light, eye, point, normal);
	return (color);
}

void	ray_manage(t_ray *ray, const int x, const int y)
{
	double		half;

	half = WALL_SIZE * 0.5;
	ray->direction = tuple_normalization(tuple_subtraction(
				set_point(-half + (WALL_SIZE / WIDTH_CANVA) * x,
					half - (WALL_SIZE / HEIGHT_CANVA) * y, 10),
				ray->origin));
}

t_inter	*intersect_manage(const t_ray ray, t_obj *obj, t_inters *xs)
{
	intersect(ray, obj, xs);
	return (hit(xs));
}

void	do_draw_sphere(const t_canvas canvas, t_obj obj)
{
	int			x;
	int			y;
	t_inter		*h;
	t_ray		ray;
	t_inters	xs;

	ray.origin = set_point(0, 0, -5);
	x = 0;
	while (x < WIDTH_CANVA)
	{
		y = 0;
		while (y < HEIGHT_CANVA)
		{
			ray_manage(&ray, x, y);
			h = intersect_manage(ray, &obj, &xs);
			if (h)
				put_px_in_canva(canvas, x, y,
					add_phong(h, position(ray, h->range), ray));
			y++;
		}
		x++;
	}
}

void	draw_sphere(const t_canvas canvas)
{
	t_obj				obj;

	obj = sphere();
	obj.material.color = set_rgb(1, 0.2, 1);
	do_draw_sphere(canvas, obj);
}
