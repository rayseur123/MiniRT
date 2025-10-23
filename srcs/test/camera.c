/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:18:16 by njooris           #+#    #+#             */
/*   Updated: 2025/10/14 11:07:31 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "transform.h"
#include "intersection.h"
#include "world.h"
#include "canvas.h"
#include "tuple.h"
#include "matrix.h"
#include "color.h"
#include "sphere.h"

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int	test_camera_1(void)
{
	const t_tuple	from = set_point(0, 0, 0);
	const t_tuple	to = set_point(0, 0, -1);
	const t_tuple	up = set_vector(0, 1, 0);
	t_matrix4	t;
	t_matrix4	identity;

	view_transform(from, to, up, t);
	set_identity_matrix(identity);
	if (!matrix4_is_equal(t, identity))
		return (1);
	return (0);
}

int	test_camera_2(void)
{
	const t_tuple	from = set_point(0, 0, 0);
	const t_tuple	to = set_point(0, 0, 1);
	const t_tuple	up = set_vector(0, 1, 0);
	t_matrix4	t;
	t_matrix4	m;

	view_transform(from, to, up, t);
	scaling(-1 , 1, -1, m);
	if (!matrix4_is_equal(t, m))
		return (1);
	return (0);
}

int	test_camera_3(void)
{
	const t_tuple	from = set_point(0, 0, 8);
	const t_tuple	to = set_point(0, 0, 0);
	const t_tuple	up = set_vector(0, 1, 0);
	t_matrix4	t;
	t_matrix4	m;

	view_transform(from, to, up, t);
	translation(0 , 0, -8, m);
	if (!matrix4_is_equal(t, m))
		return (1);
	return (0);
}

int	test_camera_4(void)
{
	const t_tuple	from = set_point(1, 3, 2);
	const t_tuple	to = set_point(4, -2, 8);
	const t_tuple	up = set_vector(1, 1, 0);
	t_matrix4	t;
	t_matrix4	m = {{-0.50709, 0.50709,  0.67612, -2.36643},
					 { 0.76772, 0.60609,  0.12122, -2.82843}, 
					 {-0.35857, 0.59761, -0.71714,  0.00000}, 
					 { 0.00000, 0.00000,  0.00000,  1.00000}};

	view_transform(from, to, up, t);
	if (!matrix4_is_equal(t, m))
		return (1);
	return (0);
}

int	test_camera_5(void)
{
	const uint32_t	hsize = 160;
	const uint32_t	vsize = 120;
	const double 	pi = 2 * acos(0.0);
	const double	fov = pi / 2;
	t_camera		c;
	t_matrix4		ident;

	set_identity_matrix(ident);
	c = camera(hsize, vsize, fov);
	if (c.vsize != vsize || c.hsize != hsize || !double_is_equal(c.fov, fov) || !matrix4_is_equal(c.transform, ident))
		return (1);
	return (0);
}

int	test_camera_6(void)
{
	t_camera		c;
	const double 	pi = 2 * acos(0.0);

	c = camera(200, 125, pi / 2);
	if (!double_is_equal(c.pixel_size,0.01))
		return (1);
	return (0);
}

int	test_camera_7(void)
{
	t_camera		c;
	const double 	pi = 2 * acos(0.0);

	c = camera(125, 200, pi / 2);
	if (!double_is_equal(c.pixel_size, 0.01))
		return (1);
	return (0);
}

int	test_camera_8(void)
{
	t_camera		c;
	t_ray			r;
	const double 	pi = 2 * acos(0.0);

	c = camera(201, 101, pi / 2);
	matrix4_inverse(c.transform, c.inverse_transform);
	r = ray_for_pixel(c, 100, 50);
	if (!check_equal_tuples(r.origin, set_point(0, 0, 0))
		|| !check_equal_tuples(r.direction, set_vector(0, 0, -1)))
		return (1);
	return (0);
}

int	test_camera_9(void)
{
	t_camera		c;
	t_ray			r;
	const double 	pi = 2 * acos(0.0);

	c = camera(201, 101, pi / 2);
	matrix4_inverse(c.transform, c.inverse_transform);
	r = ray_for_pixel(c, 0, 0);
	if (!check_equal_tuples(r.origin, set_point(0, 0, 0))
		|| !check_equal_tuples(r.direction, set_vector(0.66519, 0.33259,  -0.66851)))
		return (1);
	return (0);
}

int	test_camera_10(void)
{
	t_camera		c;
	t_ray			r;
	const double 	pi = 2 * acos(0.0);
	t_matrix4		rota;
	t_matrix4		trans;

	c = camera(201, 101, pi / 2);
	rotation_y(pi / 4, rota);
	translation(0, -2, 5, trans);
	matrix4_multiplication(rota, trans, c.transform);
	matrix4_inverse(c.transform, c.inverse_transform);
	r = ray_for_pixel(c, 100, 50);

	if (!check_equal_tuples(r.origin, set_point(0, 2, -5))
		|| !check_equal_tuples(r.direction, set_vector(sqrt(2)/2, 0, -sqrt(2)/2)))
		return (1);
	return (0);
}

int	test_camera_11(void)
{
	t_world			w;
	t_camera		c;
	const double 	pi = 2 * acos(0.0);
	t_tuple			from;
	t_tuple			to;
	t_tuple			up;
	t_canvas		img;

	w = default_world();
	c = camera(11, 11, pi/2);
	from = set_point(0, 0, -5);
	to = set_point(0, 0, 0);
	up = set_vector(0, 1, 0);
	view_transform(from, to , up, c.transform);
	matrix4_inverse(c.transform, c.inverse_transform);
	init_canva(&img);
	img = render(c, w, img);
	uint32_t grep_color = pixel_at(img, 5, 5);
	if (fcolor_to_uint(set_rgb(0.38066, 0.47583, 0.2855)) != grep_color)
		return (1);
	return (0);
}