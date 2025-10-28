/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:29:31 by dernst            #+#    #+#             */
/*   Updated: 2025/10/27 16:53:00 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tuple.h"
#include "world.h"
#include "stdbool.h"

bool	is_shadowed(t_world world, t_tuple point, t_light light)
{
	t_tuple		v;
	double		distance;
	t_ray		ray;
	t_inters	xs;
	t_inter		*h;

	v = tuple_subtraction(light.position, point);
	distance = tuple_magnitude(v);
	ray = set_ray(point, tuple_normalization(v));
	intersect_world(world, ray, &xs);
	h = hit(&xs);
	if (h && distance - h->range > EPSILON)
	{
		free(xs.inters);
		return (true);
	}
	free(xs.inters);
	return (false);
}
