/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:44:48 by njooris           #+#    #+#             */
/*   Updated: 2025/09/29 10:06:49 by njooris          ###   ########.fr       */
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
	t_sphere s;
	t_inters xs;

	r = set_ray(set_point(0, 0, -5), set_vector(0, 0 , 1));
	s = sphere();
	intersect_sphere(s, r, &xs);
	if (xs.count == 2)
	{
		printf("\n\n1 VALIDATE: %f\n\n", xs.inters[0].range);
			if (xs.inters[0].range == 4.0)
			{
				printf("\n\n 2 VALIDATE\n\n");

				if (xs.inters[1].range == 6.0)
					return (0);
			}
	}
	return (1);
}

int test_intersect_sphere_2(void)
{
	t_ray r;
	t_sphere s;
	t_inters xs;

	r = set_ray(set_point(0, 2, -5), set_vector(0, 0 , 1));
	s = sphere();
	intersect_sphere(s, r, &xs);
	if (xs.count == 0)
		return (0);
	return (1);
}

int test_intersect_sphere_3(void)
{
	t_ray r;
	t_sphere s;
	t_inters xs;

	r = set_ray(set_point(0, 0, -5), set_vector(0, 0 , 1));
	s = sphere();
	intersect_sphere(s, r, &xs);
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
	t_sphere s;
	t_inters xs;

	r = set_ray(set_point(0, 0, 5), set_vector(0, 0 , 1));
	s = sphere();
	intersect_sphere(s, r, &xs);
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