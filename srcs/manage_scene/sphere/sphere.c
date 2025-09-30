/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:14:57 by njooris           #+#    #+#             */
/*   Updated: 2025/09/30 15:33:28 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "../../../includes/scene.h"
#include <math.h>

t_obj sphere(void)
{
	static uint32_t id;
	t_obj obj;

	obj.id = id++;
	obj.type = SPHERE;
	set_identity_matrix(obj.transform);
	return (obj);
}

uint32_t intersect_sphere(t_obj *s, t_ray r, t_inters *inters)
{
	(void)s;
	const t_tuple		sphere_to_ray = tuple_subtraction(r.origin, set_point(0, 0, 0));
	const double 		a = dot_product(r.direction, r.direction);
	const double 		b = 2 * dot_product(r.direction, sphere_to_ray);
	const double		c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	const long int		discriminant = (b * b) - 4 * a * c;

	inters->count = 0;
	if (discriminant < 0)
		return (1);
	inters->count = 2;
	inters->inters[0] = set_intersection((-b - sqrt(discriminant)) / (2 * a), s);
	inters->inters[1] = set_intersection((-b + sqrt(discriminant)) / (2 * a), s);
	return (0);
}

void	set_transform(t_obj *s, t_matrix4 m)
{
	matrix4_cpy(s->transform, m);
}

void	draw_sphere(t_canvas canvas) {
	int x;
	int y;
	t_rgb color;
	t_obj s;
	t_ray r;
	t_inters inters;

	x = 0;
	r.origin = set_point(0, 0, -5);
	s = sphere();
	color = set_rgb(255, 0, 0);
	y = 0;
	while (x < WIDTH_CANVA)
	{
		y = 0;
		while (y < HEIGHT_CANVA)
		{
			r.direction = tuple_normalization(set_vector((x - WIDTH_CANVA / 2) * 0.005, (-y + HEIGHT_CANVA / 2) * 0.005, 1));
			intersect_sphere(&s, r, &inters);
			if (inters.count > 0)
				put_px_in_canva(canvas, x, y , color);
			y++;
		}
		x++;
	}
}