/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:58:07 by njooris           #+#    #+#             */
/*   Updated: 2025/09/25 13:17:46 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

int	test_translation_tuple(void)
{
	t_tuple		p;
	t_tuple		t;
	t_matrix4	m;

	translation(5, -3, 2, m);
	p = set_point(-3, 4, 5);
	t = matrix4_multiplication_by_tuple(m, p);
	if (t.x != 2 || t.y != 1 || t.z != 7)
		return (1);
	return (0);
}

int	test_translation_inverse_mtrx(void)
{
	t_tuple		p;
	t_tuple		t;
	t_matrix4	m;

	translation(5, -3, 2, m);
	matrix4_reverse(m, m);
	p = set_point(-3, 4, 5);
	t = matrix4_multiplication_by_tuple(m, p);
	if (t.x != -8 || t.y != 7 || t.z != 3)
		return (1);
	return (0);
}

int	test_translation_vector(void)
{
	t_tuple		p;
	t_tuple		t;
	t_matrix4	m;

	translation(5, -3, 2, m);
	p = set_vector(-3, 4, 5);
	t = matrix4_multiplication_by_tuple(m, p);
	if (!check_equal_tuples(t, set_vector(-3, 4, 5)))
		return (1);
	return (0);
}

int	test_scaling_to_point(void)
{
	t_matrix4	m;
	t_tuple		p;

	scaling(2, 3, 4, m);
	p = matrix4_multiplication_by_tuple(m, set_point(-4, 6, 8));
	if (!check_equal_tuples(p, set_point(-8, 18, 32)))
		return (1);
	return (0);
}

int	test_scaling_to_vector(void)
{
	t_matrix4	m;
	t_tuple		p;

	scaling(2, 3, 4, m);
	p = matrix4_multiplication_by_tuple(m, set_vector(-4, 6, 8));
	if (!check_equal_tuples(p, set_vector(-8, 18, 32)))
		return (1);
	return (0);
}

int	test_scaling_to_matrix_inverse(void)
{
	t_matrix4	m;
	t_tuple		v;

	scaling(2, 3, 4, m);
	matrix4_reverse(m, m);
	v = matrix4_multiplication_by_tuple(m, set_vector(-4, 6, 8));
	if (!check_equal_tuples(v, set_vector(-2, -2, -2)))
		return (1);
	return (0);
}

int	test_rotation_x(void)
{
	t_tuple		point;
	t_matrix4	half;
	t_matrix4	full;
	const double pi = 2 * acos(0.0);

	point = set_point(0, 1, 0);
	rotation_x(pi / 4, half);
	rotation_x(pi / 2, full);
	if (!check_equal_tuples(matrix4_multiplication_by_tuple(half, point), set_point(0, sqrt(2) / 2, sqrt(2) / 2))
			&& !check_equal_tuples(matrix4_multiplication_by_tuple(full, point), set_point(0, 0, 1)))
		return (1);
	return (0);
}

int	test_rotation_y(void)
{
	t_tuple		point;
	t_matrix4	half;
	t_matrix4	full;
	const double pi = 2 * acos(0.0);

	point = set_point(0, 0, 1);
	rotation_x(pi / 4, half);
	rotation_x(pi / 2, full);
	if (!check_equal_tuples(matrix4_multiplication_by_tuple(half, point), set_point(sqrt(2) / 2, 0, sqrt(2) / 2))
			&& !check_equal_tuples(matrix4_multiplication_by_tuple(full, point), set_point(1, 0, 0)))
		return (1);
	return (0);
}

int	test_rotation_z(void)
{
	t_tuple		point;
	t_matrix4	half;
	t_matrix4	full;
	const double pi = 2 * acos(0.0);

	point = set_point(0, 1, 0);
	rotation_x(pi / 4, half);
	rotation_x(pi / 2, full);
	if (!check_equal_tuples(matrix4_multiplication_by_tuple(half, point), set_point(-(sqrt(2) / 2), sqrt(2) / 2, 0))
			&& !check_equal_tuples(matrix4_multiplication_by_tuple(full, point), set_point(-1, 0, 0)))
		return (1);
	return (0);
}


