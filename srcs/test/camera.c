/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:18:16 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 13:37:44 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "transform.h"

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
