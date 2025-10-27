/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:59:50 by njooris           #+#    #+#             */
/*   Updated: 2025/10/23 11:32:40 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "color.h"
#include "light.h"
#include "canvas.h"
#include "sphere.h"
#include <math.h>
#include <stdlib.h>

t_inter	*intersect_manage(const t_ray ray, t_obj *obj, t_inters *xs)
{
	intersect(ray, obj, xs);
	return (hit(xs));
}

void	ray_manage(t_ray *ray, const int x, const int y)
{
	double		half;

	half = WALL_SIZE * 0.5;
	ray->direction = tuple_normalization(tuple_subtraction(
				set_point(-half + (WALL_SIZE / WIDTH_CANVA) * x,
					half - (WALL_SIZE / HEIGHT_CANVA) * y, 10),
				ray->origin));
}
