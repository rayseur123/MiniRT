/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:38:06 by njooris           #+#    #+#             */
/*   Updated: 2025/10/07 15:39:37 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	test_world_1(void)
{
	t_world w;

	w = world();
	if (w.nb_light > 0 || w.nb_obj > 0 || w.light || w.obj)
		return (1);
	return (0);
}

t_world default_world()
{
	t_world w;

	w = world();
	w.light = malloc(1 * sizeof(w.light)); 
	w.light[0] = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	w.obj = malloc(2 * sizeof(w.obj));
	w.nb_obj = 2;
	w.obj[0] = sphere();
	w.obj[1] = sphere();
	w.obj[0].material.color = set_rgb(0.8, 1.0, 0.6);
	w.obj[0].material.diffuse = 0.7;
	w.obj[0].material.spec = 0.2;
	scaling(0.5, 0.5, 0.5, w.obj[1].transform);
	return (w);
}

int	test_world_2(void)
{
	t_light l;
	t_obj	s1;
	t_obj	s2;
	t_world	w;

	w = default_world();
	l = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	if (equals_rgb(w.light->intensity, l.intensity) && check_equal_tuples(w.light->position, l.position) && w.obj[0].id == 0 && w.obj[1].id == 1)
		return (0);
	return (1);
}
