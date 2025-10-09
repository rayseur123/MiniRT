/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:38:06 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 14:37:31 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "world.h"
#include "sphere.h"
#include "transform.h"

int	test_world_0(void)
{
	t_world		w;
	t_ray		r;
	t_inters	xs;

	w = default_world();
	r = set_ray(set_point(0,0,-5), set_vector(0,0,1));
	intersect_world(w, r, &xs);
	if (xs.count == 4 && xs.inters[0].range == 4 && xs.inters[1].range == 4.5 && xs.inters[2].range == 5.5 && xs.inters[3].range == 6)
		return (0);
	return (1);
}
int	test_world_1(void)
{
	t_world w;

	w = world();
	if (w.nb_light > 0 || w.nb_obj > 0 || w.light || w.obj)
		return (1);
	return (0);
}

int	test_world_2(void)
{
	t_light l;
	t_world	w;

	w = default_world();
	l = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	if (equals_rgb(w.light->intensity, l.intensity) && check_equal_tuples(w.light->position, l.position) && w.obj[0].id == 0 && w.obj[1].id == 1)
		return (0);
	return (1);
}

int	test_world_3(void)
{
	t_ray	r;
	t_obj	o;
	t_inter	inter;

	r = set_ray(set_point(0,0,-5), set_vector(0,0,1));
	o = sphere();
	inter = set_intersection(4, &o);
	prepare_computations(&inter, r);
	if (inter.range == 4 && check_equal_tuples(inter.point, set_point(0,0, -1)) && check_equal_tuples(inter.eyev, set_vector(0,0,-1)) && check_equal_tuples(inter.normalv, set_vector(0,0,-1)))
		return (0);
	return (1);
}

int	test_world_4(void)
{
	t_ray	r;
	t_obj	o;
	t_inter	inter;

	r = set_ray(set_point(0,0,-5), set_vector(0,0,1));
	o = sphere();
	inter = set_intersection(1, &o);
	prepare_computations(&inter, r);
	if (check_equal_tuples(inter.point, set_point(0,0, 1)) && check_equal_tuples(inter.eyev, set_vector(0,0,-1)) && check_equal_tuples(inter.normalv, set_vector(0,0,-1)) && inter.inside == true)
		return (1);
	return (0);
}

int	test_world_5(void)
{
	t_world	w;
	t_ray	r;
	t_obj	o;
	t_inter	inter;
	t_rgb	c;

	w = default_world();
	r = set_ray(set_point(0,0,-5), set_vector(0,0,1));
	o = sphere();
	inter = set_intersection(4, &o);
	prepare_computations(&inter, r);
	c = shade_hit(w, inter);
	if (equals_rgb(c, set_rgb(0.38066,0.47583,0.2855)))
		return (1);
	return (0);
}

int	test_world_6(void)
{
	t_world	w;
	t_ray	r;
	t_obj	o;
	t_inter	inter;
	t_rgb	c;

	w = default_world();
	w.light[0] = point_light(set_point(0, 0.25, 0), set_rgb(1, 1, 1));
	r = set_ray(set_point(0,0,0), set_vector(0,0,1));
	o = sphere();
	inter = set_intersection(0.5, &o);
	prepare_computations(&inter, r);
	c = shade_hit(w, inter);
	if (!equals_rgb(c, set_rgb(0.90498,0.90498,0.90498)))
		return (1);
	return (0);
}

int	test_world_7(void)
{
	t_world	w;
	t_ray	r;
	t_rgb	c;

	w = default_world();
	r = set_ray(set_point(0,0,-5), set_vector(0,1,0));
	c = color_at(w, r);
	if (!equals_rgb(c , set_rgb(0,0,0)))
		return (1);
	return (0);
}

int	test_world_8(void)
{
	t_world	w;
	t_ray	r;
	t_rgb	c;

	w = default_world();
	r = set_ray(set_point(0,0,-5), set_vector(0,0,1));
	c = color_at(w, r);
	if (!equals_rgb(c , set_rgb(0.38066,0.47583,0.2855)))
		return (1);
	return (0);
}

int	test_world_9(void)
{
	t_world	w;
	t_ray	r;
	t_rgb	c;

	w = default_world();
	w.obj[0].material.ambient = 1;
	w.obj[1].material.ambient = 1;
	r = set_ray(set_point(0,0,0.75), set_vector(0,0,-1));
	c = color_at(w, r);
	if (!equals_rgb(c , w.obj[1].material.color))
		return (1);
	return (0);
}