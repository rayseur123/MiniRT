/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:56:29 by dernst            #+#    #+#             */
/*   Updated: 2025/11/06 14:56:41 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "intersection.h"
#include "transform.h"
#include <math.h>
#include "object.h"

int	test_shape1(void)
{
	t_obj	s;
	t_matrix4 m;

	set_identity_matrix(m);
	s = shape(SPHERE);
	if (matrix4_is_equal(s.transform, m))
		return (0);
	return (1);
}

int	test_shape2(void)
{
	t_obj	s;
	t_matrix4 m;

	set_transform(&s, translation(2, 3, 4, m));
	if (matrix4_is_equal(s.transform, translation(2, 3, 4, m)))
		return (0);
	return (1);
}

int	test_shape6(void)
{
	const double pi = 2 * acos(0.0);
	t_obj		s;
	t_matrix4	m;
	t_tuple		n;

	s = shape(SPHERE);
	scaling(1, 0.5, 1, m);
	rotation_z(pi / 5, m);
	set_transform(&s, m);
	n = normal_at(s, set_point(0, sqrt(2)/2, -sqrt(2)/2));
	if (check_equal_tuples(n, set_vector(0, 0.70711, -0.70711)))
		return (0);
	return (1);
}

int test_plane0(void)
{
	t_obj	p;
	t_tuple n1;
	t_tuple n2;
	t_tuple n3;

	p = shape(PLANE);
	n1 = shape_normal_at(p, set_point(0, 0, 0));
	n2 = shape_normal_at(p, set_point(10, 0, -10));
	n3 = shape_normal_at(p, set_point(-5, 0, 150));
	if (check_equal_tuples(n1, set_point(0, 1, 0)) && check_equal_tuples(n2, set_point(0, 1, 0)) && check_equal_tuples(n3, set_point(0, 1, 0)))
		return (0);
	return (1);
}

int test_plane1(void)
{
	t_obj	p;
	t_ray	r;
	t_inters xs;

	p = shape(PLANE);
	r = set_ray(set_point(0, 10, 0), set_vector(0, 0, 1));
	xs.inters = malloc(2 * sizeof(t_inter));
	xs.count = 0;
	intersect(r, &p, &xs);
	if (!xs.count)
		return (0);
	return (1);
}

int test_plane2(void)
{
	t_obj	p;
	t_ray	r;
	t_inters xs;

	p = shape(PLANE);
	r = set_ray(set_point(0, 0, 0), set_vector(0, 0, 1));
	xs.inters = malloc(2 * sizeof(t_inter));
	xs.count = 0;
	intersect(r, &p, &xs);
	if (!xs.count)
		return (0);
	return (1);
}

int	test_plane3(void)
{
	t_obj	p;
	t_ray	r;
	t_inters xs;

	p = shape(PLANE);
	r = set_ray(set_point(0, 0, 0), set_vector(0, 0, 1));
	xs.inters = malloc(2 * sizeof(t_inter));
	xs.count = 0;
	intersect(r, &p, &xs);
	if (!xs.count)
		return (0);
	return (1);
}

int test_cylinder1(void)
{
	unsigned int i;
	t_obj c;
	t_ray	r;
	t_inters xs;

	i = 0;
	while (i < 3)
	{
		xs.inters = malloc(2 * sizeof(t_inter));
		xs.count = 0;
		if (i == 0)
			r = set_ray(set_point(1, 0, 0), set_vector(0, 1, 0));
		else if (i == 1)
			r = set_ray(set_point(0, 0, 0), set_vector(0, 1, 0));
		else if (i == 2)
			r = set_ray(set_point(0, 0, -5), set_vector(1, 1, 1));
		intersect_cylinder(&c, r, &xs);
		if (xs.count > 0)
			return (1);
		i++;
	}
	return (0);
}