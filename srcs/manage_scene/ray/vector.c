/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:49:54 by njooris           #+#    #+#             */
/*   Updated: 2025/10/29 15:36:58 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "matrix.h"
#include "intersection.h"

t_tuple	shape_normal_at(t_obj o, t_tuple op)
{
	double	t;
	if (o.type == SPHERE)
		return (tuple_subtraction(op, set_point(0, 0, 0)));
	if (o.type == PLANE)
		return (set_vector(0, 1, 0));
	if (o.type == CYLINDER)
	{
		if (o.closed)
		{
			t = op.x * op.x + op.z * op.z;
			if (t < 1 && op.y >= o.max - EPSILON)
				return (set_vector(0, 1, 0));
			if (t < 1 && op.y <= o.min + EPSILON)
				return (set_vector(0, -1, 0));
		}
		return (set_vector(op.x, 0 , op.z));
	}
	return (set_point(0, 0, 0));
}

t_tuple	normal_at(t_obj s, t_tuple wp)
{
	t_tuple		op;
	t_tuple		on;
	t_tuple		wn;

	op = matrix4_multiplication_by_tuple(s.inverse_transform, wp);
	on = shape_normal_at(s, op);
	wn = matrix4_multiplication_by_tuple(matrix4_transposition(
				s.inverse_transform), on);
	wn.w = 0;
	return (tuple_normalization(wn));
}

t_tuple	reflect(t_tuple	in, t_tuple n)
{
	return (tuple_subtraction(in,
			tuple_multiplication(tuple_multiplication(n, 2),
				dot_product(in, n))));
}
