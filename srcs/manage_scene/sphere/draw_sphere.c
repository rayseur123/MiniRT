/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:59:50 by njooris           #+#    #+#             */
/*   Updated: 2025/10/13 13:03:45 by njooris          ###   ########.fr       */
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

t_rgb	add_phong(const t_inter *h, const t_tuple point, t_ray ray)
{
	t_light	light;
	t_tuple	normal;
	t_tuple	eye;
	t_rgb	color;

	light = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	normal = normal_at(*h->obj, point);
	eye = tuple_negation(ray.direction);
	color = lighting(h->obj->material, light, eye, point, normal);
	return (color);
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

void	do_draw_sphere(const t_canvas canvas, t_obj obj)
{
	int			x;
	int			y;
	t_inter		*h;
	t_ray		ray;
	t_inters	xs;

	xs.inters = malloc(2 * sizeof(t_inter));
	ray.origin = set_point(0, 0, -5);
	x = 0;
	while (x < WIDTH_CANVA)
	{
		y = 0;
		while (y < HEIGHT_CANVA)
		{
			xs.count = 0;
			ray_manage(&ray, x, y);
			h = intersect_manage(ray, &obj, &xs);
			if (h)
				put_px_in_canva(canvas, x, y,
					add_phong(h, position(ray, h->range), ray));
			y++;
		}
		x++;
	}
}

void	draw_sphere(const t_canvas canvas)
{
	t_obj				obj;

	obj = sphere();
	obj.material.color = set_rgb(1, 0.2, 1);
	do_draw_sphere(canvas, obj);
}
