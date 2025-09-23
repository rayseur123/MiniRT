/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:58:07 by njooris           #+#    #+#             */
/*   Updated: 2025/09/23 13:27:48 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

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
	p = set_point(-4, 6, 8);
	if (!check_equal_tuples(p, set_point(-8, 18, 32)))
		return (1);
	return (0);
}

int	test_scaling_to_vector(void)
{
	t_matrix4	m;
	t_tuple		p;

	scaling(2, 3, 4, m);
	p = set_vector(-4, 6, 8);
	if (!check_equal_tuples(p, set_vector(-8, 18, 32)))
		return (1);
	return (0);
}

