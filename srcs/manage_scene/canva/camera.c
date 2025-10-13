/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:38:53 by njooris           #+#    #+#             */
/*   Updated: 2025/10/13 15:35:59 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrix.h"
#include "camera.h"
#include "transform.h"
#include "intersection.h"
#include "canvas.h"
#include "world.h"

t_matrix4_ptr	view_transform(t_tuple from, t_tuple to, t_tuple up,
					t_matrix4 r)
{
	t_matrix4	m;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix4	trans;

	forward = tuple_normalization(tuple_subtraction(to, from));
	left = cross_product(forward, tuple_normalization(up));
	true_up = cross_product(left, forward);
	set_identity_matrix(m);
	m[0][0] = left.x;
	m[0][1] = left.y;
	m[0][2] = left.z;
	m[1][0] = true_up.x;
	m[1][1] = true_up.y;
	m[1][2] = true_up.z;
	m[2][0] = -forward.x;
	m[2][1] = -forward.y;
	m[2][2] = -forward.z;
	translation(-from.x, -from.y, -from.z, trans);
	return (matrix4_multiplication(m, trans, r));
}

t_camera	camera(double hsize, double vsize, double fov)
{
	t_camera	c;
	double		half_view;
	double		aspect;

	c.fov = fov;
	c.hsize = hsize;
	c.vsize = vsize;
	half_view = tan(c.fov / 2);
	aspect = c.hsize / c.vsize;
	if (aspect >= 1)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	set_identity_matrix(c.transform);
	return (c);
}

t_ray	ray_for_pixel(t_camera c, uint32_t px, uint32_t py)
{
	const double	world_x = c.half_width - (px + 0.5) * c.pixel_size;
	const double	world_y = c.half_height - (py + 0.5) * c.pixel_size;
	t_tuple			pixel;
	t_tuple			origin;

	pixel = matrix4_multiplication_by_tuple(c.inverse_transform,
			set_point(world_x, world_y, -1));
	origin = matrix4_multiplication_by_tuple(c.inverse_transform, set_point(0, 0, 0));
	return (set_ray(origin, tuple_normalization(
				tuple_subtraction(pixel, origin))));
}

t_canvas	render(t_camera c, t_world w, t_canvas img)
{
	int		x;
	int		y;
	t_ray	r;
	t_rgb	color;

	x = 0;
	while (x < c.hsize)
	{
		y = 0;
		while (y < c.vsize)
		{
			r = ray_for_pixel(c, x, y);
			color = color_at(w, r);
			put_px_in_canva(img, x, y, color);
			y++;
		}
		x++;
	}
	return (img);
}
