/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:37:35 by njooris           #+#    #+#             */
/*   Updated: 2025/11/18 11:07:08 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "shadow.h"
#include <fcntl.h>
#include "minirt_error.h"
#include "unistd.h"

uint8_t	world(t_world *w)
{
	int fd;
	uint32_t	seed;

	w->nb_light = 0;
	w->nb_obj = 0;
	w->light = NULL;
	w->obj = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		print_error(FD_ERROR);
		return (1);
	}
	if (read(fd, &seed, 4) == -1)
		return (1);
	close(fd);
	return (0);
}

void	intersect_world(t_world w, t_ray r, t_linter *inters)
{
	unsigned int	i;

	inters->count = 0;
	i = 0;
	while (i < w.nb_obj)
		intersect(r, &w.obj[i++], inters);
	recursive(inters->inters, 0, inters->count - 1);
}

t_comp	prepare_computations(t_inter *inter, const t_ray ray)
{
	t_comp	comp;

	comp.point = position(ray, inter->range);
	comp.eyev = tuple_negation(ray.direction);
	comp.normalv = normal_at(inter->obj[0], comp.point);
	comp.material = inter->obj->material;
	if (dot_product(comp.normalv, comp.eyev) < 0)
	{
		comp.inside = true;
		comp.normalv = tuple_negation(comp.normalv);
	}
	else
		comp.inside = false;
	comp.over_point = tuple_addition(comp.point,
			tuple_multiplication(comp.normalv, EPSILON));
	return (comp);
}

t_rgb	shade_hit(t_world world, t_comp comps, t_linter linter)
{
	unsigned int	i;
	t_lighting		l;
	t_rgb			color;

	color = set_rgb(0, 0, 0);
	i = 0;
	while (i < world.nb_light)
	{
		l.mat = comps.material;
		l.light = world.light[i];
		l.eyev = comps.eyev;
		color = rgb_addition(color, lighting(l,
					comps.point, comps.normalv, is_shadowed(world,
						comps.over_point, world.light[i], linter)));
		i++;
	}
	return (color);
}
