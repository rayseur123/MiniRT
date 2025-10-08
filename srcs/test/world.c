/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:38:06 by njooris           #+#    #+#             */
/*   Updated: 2025/10/08 13:14:21 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"
#include <stdlib.h>
#include <stdio.h>

t_world default_world()
{
	t_world w;

	w = world();
	w.light = malloc(4 * sizeof(t_light));
	w.light[0] = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	w.obj = malloc(4 * sizeof(t_obj));
	w.nb_obj = 2;
	w.obj[0] = sphere();
	w.obj[1] = sphere();
	w.obj[0].material.color = set_rgb(0.8, 1.0, 0.6);
	w.obj[0].material.diffuse = 0.7;
	w.obj[0].material.spec = 0.2;
	scaling(0.5, 0.5, 0.5, w.obj[1].transform);
	return (w);
}
int	test_world_0(void)
{
	t_world		w;
	t_ray		r;
	t_inters	xs;

	w = default_world();
	r = set_ray(set_point(0,0,-5), set_vector(0,0,1));
	intersect_world(w, r, &xs);
	printf("count:%d\n", xs.count);
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




