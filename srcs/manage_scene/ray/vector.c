/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:49:54 by njooris           #+#    #+#             */
/*   Updated: 2025/10/24 15:15:30 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "matrix.h"
#include "intersection.h"

t_tuple	normal_at(t_obj s, t_tuple wp)
{
	t_tuple		op;
	t_tuple		on;
	t_tuple		wn;

	op = matrix4_multiplication_by_tuple(s.inverse_transform, wp);
	on = tuple_subtraction(op, set_point(0, 0, 0));
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
