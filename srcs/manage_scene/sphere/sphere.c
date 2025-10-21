/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:14:57 by njooris           #+#    #+#             */
/*   Updated: 2025/10/21 13:09:26 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "color.h"
#include "light.h"
#include "canvas.h"
#include <math.h>
#include <stdlib.h>

t_material	material(void)
{
	t_material	mat;

	mat.ambient = 0.0;
	mat.diffuse = 0.9;
	mat.spec = 0.9;
	mat.shininess = 200;
	mat.color = set_rgb(1, 1, 1);
	return (mat);
}

t_obj	sphere(void)
{
	static int32_t	id;
	t_obj			obj;

	obj.id = id++;
	obj.type = SPHERE;
	obj.material = material();
	set_identity_matrix(obj.transform);
	set_identity_matrix(obj.inverse_transform);
	return (obj);
}

uint32_t	intersect_sphere(t_obj *s, const t_ray r, t_inters *inters)
{
	const t_tuple		sphere_to_ray = tuple_subtraction(r.origin,
			set_point(0, 0, 0));
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
