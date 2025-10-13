/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_tuple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:06:00 by njooris           #+#    #+#             */
/*   Updated: 2025/10/13 12:31:30 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <math.h>

t_tuple	tuple_addition(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	tuple;

	tuple.x = tuple1.x + tuple2.x;
	tuple.y = tuple1.y + tuple2.y;
	tuple.z = tuple1.z + tuple2.z;
	tuple.w = tuple1.w + tuple2.w;
	return (tuple);
}

t_tuple	tuple_subtraction(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	tuple;

	tuple.x = tuple1.x - tuple2.x;
	tuple.y = tuple1.y - tuple2.y;
	tuple.z = tuple1.z - tuple2.z;
	tuple.w = tuple1.w - tuple2.w;
	return (tuple);
}

t_tuple	tuple_multiplication(t_tuple tuple1, double scale)
{
	tuple1.x *= scale;
	tuple1.y *= scale;
	tuple1.z *= scale;
	return (tuple1);
}

t_tuple	tuple_division(t_tuple tuple1, double scale)
{
	if (scale == 0)
		return (tuple1);
	tuple1.x = tuple1.x / scale;
	tuple1.y = tuple1.y / scale;
	tuple1.z = tuple1.z / scale;
	return (tuple1);
}

t_tuple	tuple_negation(t_tuple tuple)
{
	return ((t_tuple){tuple.x * -1, tuple.y * -1,
		tuple.z * -1, tuple.w * -1});
}
