/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:37:35 by njooris           #+#    #+#             */
/*   Updated: 2025/11/06 16:30:35 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "stdlib.h"
#include <stdio.h>
#include "shadow.h"
#include <sys/stat.h>
#include <fcntl.h>

t_world	world(void)
{
	t_world	w;

	w.nb_light = 0;
	w.nb_obj = 0;
	w.light = NULL;
	w.obj = 0;
	w.fd = open("/dev/random", O_RDONLY);
	return (w);
}

uint32_t	intersect_world(t_world w, t_ray r, t_linter *inters)
{
	unsigned int	i;

	inters->count = 0;
	i = 0;
	while (i < w.nb_obj)
		intersect(r, &w.obj[i++], inters);
	recursive(inters->inters, 0, inters->count - 1);
	return (0);
}

void	prepare_computations(t_inter *inter, const t_ray ray)
{
	inter->point = position(ray, inter->range);
	inter->eyev = tuple_negation(ray.direction);
	inter->normalv = normal_at(inter->obj[0], inter->point);
	if (dot_product(inter->normalv, inter->eyev) < 0)
	{
		inter->inside = true;
		inter->normalv = tuple_negation(inter->normalv);
	}
	else
		inter->inside = false;
	inter->over_point = tuple_addition(inter->point,
			tuple_multiplication(inter->normalv, EPSILON));
}

t_rgb	shade_hit(t_world world, t_inter comps, t_linter linter)
{
	unsigned int	i;
	t_lighting		l;
	t_rgb			color;

	color = set_rgb(0, 0, 0);
	i = 0;
	while (i < world.nb_light)
	{
		l.mat = comps.obj->material;
		l.light = world.light[i];
		l.eyev = comps.eyev;
		color = rgb_addition(color, lighting(l,
					comps.point, comps.normalv, is_shadowed(world,
						comps.over_point, world.light[i], linter)));
		i++;
	}
	return (color);
}
