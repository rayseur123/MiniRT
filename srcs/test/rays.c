/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:44:48 by njooris           #+#    #+#             */
/*   Updated: 2025/09/30 10:55:08 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "../../includes/scene.h"
#include <stdio.h>

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

	s.type = SPHERE;
	i1 = set_intersection(1, &s);
	i2 = set_intersection(2, &s);
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
	intersect_sphere(&s, r, &xs);
	if (xs.count == 2) {
		if (xs.inters[0].obj->id == s.id && xs.inters[1].obj->id == s.id)
			return (0);
	}
	return (1);
}
