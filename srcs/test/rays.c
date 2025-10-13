/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:44:48 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 10:30:03 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tuple.h"
#include "intersection.h"
#include "sphere.h"
#include "transform.h"
#include <math.h>

int	test_ray_position(void)
{
	t_ray ray;

	ray.origin = set_point(2, 3, 4);
	ray.direction = set_vector(1, 0, 0);
	if (!check_equal_tuples(position(ray, 0.0), set_point(2, 3, 4)))
		return (1);
	if (!check_equal_tuples(position(ray, 1.0), set_point(3, 3, 4)))
		return (1);
	if (!check_equal_tuples(position(ray, -1.0), set_point(1, 3, 4)))
		return (1);
	if (!check_equal_tuples(position(ray, 2.5), set_point(4.5, 3, 4)))
		return (1);
	return (0);
}

int test_intersect_sphere_1(void)
{
	t_ray r;
	t_obj s;
	t_inters xs;

	r = set_ray(set_point(0, 0, -5), set_vector(0, 0 , 1));
	s = sphere();
	xs.count = 0;
	xs.inters = malloc(2 *sizeof(t_inter));
	intersect_sphere(&s, r, &xs);
	if (xs.count == 2)
	{
			if (xs.inters[0].range == 4.0)
			{
				if (xs.inters[1].range == 6.0)
					return (0);
			}
	}
	return (1);
}

int test_intersect_sphere_2(void)
{
	t_ray r;
	t_obj s;
	t_inters xs;

	r = set_ray(set_point(0, 2, -5), set_vector(0, 0 , 1));
	s = sphere();
	xs.count = 0;
	xs.inters = malloc(2 *sizeof(t_inter));
	intersect_sphere(&s, r, &xs);
	if (xs.count == 0)
		return (0);
	return (1);
}

int test_intersect_sphere_3(void)
{
	t_ray r;
	t_obj s;
	t_inters xs;

	r = set_ray(set_point(0, 0, 0), set_vector(0, 0 , 1));
	s = sphere();
	xs.count = 0;
	xs.inters = malloc(2 *sizeof(t_inter));
	intersect_sphere(&s, r, &xs);
	if (xs.count == 2)
	{
		if (xs.inters[0].range == -1.0)
		{
			if (xs.inters[1].range == 1.0)
				return (0);
		}
	}
	return (1);
}

int test_intersect_sphere_4(void)
{
	t_ray r;
	t_obj s;
	t_inters xs;

	r = set_ray(set_point(0, 0, 5), set_vector(0, 0 , 1));
	s = sphere();
	xs.count = 0;
	xs.inters = malloc(2 *sizeof(t_inter));
	intersect_sphere(&s, r, &xs);
	if (xs.count == 2)
	{
		if (xs.inters[0].range == -6.0)
		{
			if (xs.inters[1].range == -4.0)
				return (0);
		}
	}
	return (1);
}

// NOT FINISH MISSING A VERIF ON THE OBJ
int	test_set_intersection(void)
{
	t_obj s;
	t_inter i;

	s = sphere();
	i = set_intersection(3.5, &s);
	if (i.range == 3.5)
		if (i.obj->id == s.id)
			return (0);
	return (1);
}

int test_aggregating_intersection(void)
{
	t_obj s;
	t_inter i1;
	t_inter i2;
	t_inters xs;

	s = sphere();
	i1 = set_intersection(1, &s);
	i2 = set_intersection(2, &s);
	xs.count = 0;
	set_intersections(&xs, i1, i2);
	if (xs.count == 2) {
		if (xs.inters[0].obj->id == s.id && xs.inters[1].obj->id == s.id)
			return (0);
	}
	return (1);
}

int test_intersection_objet(void)
{
	t_ray r;
	t_obj s;
	t_inters xs;

	r = set_ray(set_point(0, 0, -5), set_vector(0, 0 , 1));
	s = sphere();
	s.type = SPHERE;
	xs.count = 0;
	xs.inters = malloc(2 * sizeof(t_inter));
	intersect_sphere(&s, r, &xs);
	if (xs.count == 2) {
		if (xs.inters[0].obj->id == s.id && xs.inters[1].obj->id == s.id)
			return (0);
	}
	return (1);
}

int	test_hit_1(void)
{
	t_obj	s;
	t_inter	i1;
	t_inter i2;
	t_inters xs;

	s = sphere();
	
	i1 = set_intersection(1, &s);
	i2 = set_intersection(2, &s);
	xs.count = 0;
	set_intersections(&xs, i1, i2);
	if (hit(&xs)->range != 1.0)
		return (1);
	return (0);
}

int	test_hit_2(void)
{
	t_obj	s;
	t_inter	i1;
	t_inter i2;
	t_inters xs;

	s = sphere();
	
	i1 = set_intersection(-1, &s);
	i2 = set_intersection(1, &s);
	set_intersections(&xs, i1, i2);
	if (hit(&xs)->range != 1)
		return (1);
	return (0);
}

int	test_hit_3(void)
{
	t_obj	s;
	t_inter	i1;
	t_inter i2;
	t_inters xs;

	s = sphere();
	
	i1 = set_intersection(-2, &s);
	i2 = set_intersection(-1, &s);
	xs.count = 0;
	set_intersections(&xs, i1, i2);
	if (hit(&xs))
		return (1);
	return (0);
}

int	test_transfrom_1(void)
{
	t_ray 		r;
	t_ray		r2;
	t_matrix4	m;

	r = set_ray(set_point(1, 2, 3), set_vector(0, 1, 0));
	translation(3, 4, 5, m);
	r2 = transform(r, m);
	if (!check_equal_tuples(r2.origin, set_point(4, 6, 8))
		|| !check_equal_tuples(r2.direction, set_point(0, 1, 0)))
		return (1);
	return (0);
}

int	test_transfrom_2(void)
{
	t_ray 		r;
	t_ray		r2;
	t_matrix4	m;

	r = set_ray(set_point(1, 2, 3), set_vector(0, 1, 0));
	scaling(2, 3, 4, m);
	r2 = transform(r, m);
	if (!check_equal_tuples(r2.origin, set_point(2, 6, 12))
		|| !check_equal_tuples(r2.direction, set_point(0, 3, 0)))
		return (1);
	return (0);
}

int	test_transfrom_3(void)
{
	t_obj		s;
	t_matrix4	m;

	set_identity_matrix(s.transform);
	set_identity_matrix(m);

	if (!matrix4_is_equal(s.transform, m))
		return (1);
	return (0);
}

int	test_transfrom_4(void)
{
	t_obj		s;
	t_matrix4	m;

	set_identity_matrix(s.transform);
	translation(2, 3, 4, m);
	set_transform(&s, m);
	if (!matrix4_is_equal(s.transform, m))
		return (1);
	return (0);
}

int	test_transfrom_5(void)
{
	t_ray		r;
	t_obj		s;
	t_matrix4	m;
	t_inters	xs;

	r = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	s = sphere();
	scaling(2, 2, 2, m);
	set_transform(&s, m);
	xs.count = 0;
	xs.inters = malloc(2 * sizeof(t_inter));
	intersect(r, &s, &xs);
	if (xs.count != 2 || !double_is_equal(xs.inters[0].range, 3.0)
		|| !double_is_equal(xs.inters[1].range, 7.0))
		return (1);
	return (0);
}

int	test_transfrom_6(void)
{
	t_ray		r;
	t_obj		s;
	t_matrix4	m;
	t_inters	xs;

	r = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	s = sphere();
	translation(5, 0, 0, m);
	set_transform(&s, m);
	xs.count = 0;
	xs.inters = malloc(2 * sizeof(t_inter));
	intersect(r, &s, &xs);
	if (xs.count != 0)
		return (1);
	return (0);
}

int	test_normal_vector_on_sphere1(void)
{
	t_obj	s;
	t_tuple	v;

	s = sphere();
	v = normal_at(s, set_point(1, 0, 0));
	if (!check_equal_tuples(v, set_vector(1, 0, 0)))
		return (1);
	return (0);
}

int	test_normal_vector_on_sphere2(void)
{
	t_obj	s;
	t_tuple	v;

	s = sphere();
	v = normal_at(s, set_point(0, 1, 0));
	if (!check_equal_tuples(v, set_vector(0, 1, 0)))
		return (1);
	return (0);
}

int	test_normal_vector_on_sphere3(void)
{
	t_obj	s;
	t_tuple	v;

	s = sphere();
	v = normal_at(s, set_point(0, 0, 1));
	if (!check_equal_tuples(v, set_vector(0, 0, 1)))
		return (1);
	return (0);
}

int	test_normal_vector_on_sphere4(void)
{
	t_obj	s;
	t_tuple	v;

	s = sphere();
	v = normal_at(s, set_point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
	if (!check_equal_tuples(v, set_vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3)))
		return (1);
	return (0);
}

int	test_normal_vector_on_sphere5(void)
{
	t_obj	s;
	t_tuple	v;

	s = sphere();
	v = normal_at(s, set_point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
	if (!check_equal_tuples(v, tuple_normalization(v)))
		return (1);
	return (0);
}

int	test_normal_vector_on_sphere6(void)
{
	t_obj		s;
	t_tuple		v;
	t_matrix4 	m;

	s = sphere();
	set_transform(&s, translation(0, 1, 0, m));
	v = normal_at(s, set_point(0,  1.70711, -0.70711));
	if (!check_equal_tuples(v, set_point(0,  0.70711, -0.70711)))
		return (1);
	return (0);
}

int	test_normal_vector_on_sphere7(void)
{
	t_obj		s;
	t_tuple		v;
	t_matrix4 	m;
	t_matrix4	scale;
	t_matrix4	rota;
	const double pi = 2 * acos(0.0);

	s = sphere();
	scaling(1, 0.5, 1, scale);
	rotation_z(pi / 5, rota);
	matrix4_multiplication(scale, rota, m);
	set_transform(&s, m);
	v = normal_at(s, set_point(0,  sqrt(2) / 2, -(sqrt(2) / 2)));
	if (!check_equal_tuples(v, set_vector(0,  0.97014, -0.24254)))
		return (1);
	return (0);
}

int	test_reflect_vector_on_sphere1(void)
{
	t_tuple	v;
	t_tuple	n;
	t_tuple	r;

	v = set_vector(1, -1, 0);
	n = set_vector(0, 1, 0);
	r = reflect(v, n);
	if (!check_equal_tuples(r, set_vector(1, 1, 0)))
		return (1);
	return (0);
}

int	test_reflect_vector_on_sphere2(void)
{
	t_tuple	v;
	t_tuple	n;
	t_tuple	r;

	v = set_vector(0, -1, 0);
	n = set_vector(sqrt(2) / 2, sqrt(2) / 2, 0);
	r = reflect(v, n);
	if (!check_equal_tuples(r, set_vector(1, 0, 0)))
		return (1);
	return (0);
}