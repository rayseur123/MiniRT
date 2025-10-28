/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:51:20 by dernst            #+#    #+#             */
/*   Updated: 2025/10/27 14:05:09 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shadow.h>
#include <stdbool.h>
#include <stdlib.h>
#include <transform.h>
#include <world.h>
#include "light.h"
#include "tuple.h"

int	test_shadow1(void)
{
	t_tuple normalv;
	t_rgb	result;
	bool	in_shadow;
	t_lighting l;

	l.eyev = set_vector(0, 0, -1);
	normalv = set_vector(0, 0, -1);
	l.light = point_light(set_point(0, 0, -10), set_rgb(1, 1, 1));
	l.mat = material();
	in_shadow = true;
	result = lighting(l, set_point(0,0,0), normalv, in_shadow);
	if (equals_rgb(result, set_rgb(0.1,0.1,0.1)))
		return (false);
	return (true);
}

int	test_shadow2(void)
{
	t_world	w;
	t_tuple	p;

	w = default_world();
	p = set_point(0,10,0);
	if (is_shadowed(w,p,w.light[0]))
		return (1);
	return (0);
}

int	test_shadow3(void)
{
	t_world	w;
	t_tuple	p;

	w = default_world();
	p = set_point(10,-10,10);
	if (!is_shadowed(w,p,w.light[0]))
		return (1);
	return (0);
}

int	test_shadow4(void)
{
	t_world	w;
	t_tuple	p;

	w = default_world();
	p = set_point(-20,20,-20);
	if (is_shadowed(w,p,w.light[0]))
		return (1);
	return (0);
}

int	test_shadow5(void)
{
	t_world	w;
	t_tuple	p;

	w = default_world();
	p = set_point(-2,2,-2);
	if (is_shadowed(w,p, w.light[0]))
		return (1);
	return (0);
}

int	test_shadow6(void)
{
	t_world	w;
	t_ray	r;
	t_inter i;
	t_rgb	c;

	w = world();
	w.light = malloc(sizeof(t_light));
	w.nb_light = 1;
	w.light[0] = point_light(set_point(0,0,-10), set_rgb(1,1,1));
	w.obj = malloc(2 * sizeof(t_obj));
	w.nb_obj = 2;
	w.obj[0] = shape(SPHERE);
	w.obj[1] = shape(SPHERE);
	translation(0,0,10, w.obj[1].transform);
	matrix4_inverse(w.obj[1].transform, w.obj[1].inverse_transform);
	r = set_ray(set_point(0,0,5), set_vector(0,0,1));
	i = set_intersection(4, &w.obj[1]);
	prepare_computations(&i, r);
	c = shade_hit(w, i);
	if (!equals_rgb(c, set_rgb(0.1,0.1,0.1)))
		return (1);
	return (0);
}

int	test_shadow7(void)
{
	t_ray r;
	t_obj sphere;
	t_inter i;

	r = set_ray(set_point(0,0,-5), set_vector(0,0,1));
	sphere = shape(SPHERE);
	translation(0,0,1,sphere.transform);
	matrix4_inverse(sphere.transform, sphere.inverse_transform);
	i = set_intersection(5, &sphere);
	prepare_computations(&i, r);
	if (i.over_point.z >= -EPSILON / 2 && i.point.z < i.over_point.z)
		return (1);
	return (0);
}
