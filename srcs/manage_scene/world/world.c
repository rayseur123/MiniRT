/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:37:35 by njooris           #+#    #+#             */
/*   Updated: 2025/10/13 16:14:36 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "sphere.h"
#include "stdlib.h"
#include "transform.h"
#include <stdio.h>

t_world	world(void)
{
	t_world	w;

	w.nb_light = 0;
	w.nb_obj = 0;
	w.light = NULL;
	w.obj = 0;
	return (w);
}

void	sort_intersection(t_inters *inters)
{
	t_inter			temp;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	new_count;

	i = -1;
	new_count = inters->count;
	while (++i < inters->count)
	{
		j = i - 1;
		k = i;
		if (inters->inters[i].range < 0)
			new_count--;
		while (++j < inters->count)
		{
			if (inters->inters[j].range < inters->inters[k].range
				&& inters->inters[j].obj > 0)
				k = j;
		}
		temp = inters->inters[i];
		inters->inters[i] = inters->inters[k];
		inters->inters[k] = temp;
	}
	inters->count = new_count;
}

uint32_t	intersect_world(t_world w, t_ray r, t_inters *inters)
{
	unsigned int	i;

	i = 0;
	inters->inters = malloc((2 * w.nb_obj) * sizeof(t_inter));
	inters->count = 0;
	while (i < w.nb_obj)
	{
		intersect(r, &w.obj[i], inters);
		i++;
	}
	sort_intersection(inters);
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
}

t_rgb	shade_hit(t_world world, t_inter comps)
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
		color = rgb_addition(color, lighting(l, comps.eyev,
					comps.point, comps.normalv));
		i++;
	}
	return (color);
}
