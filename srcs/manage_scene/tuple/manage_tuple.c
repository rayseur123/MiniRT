/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:41:52 by njooris           #+#    #+#             */
/*   Updated: 2025/11/12 17:31:35 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <math.h>

double	tuple_magnitude(t_tuple tuple)
{
	return (sqrt(tuple.x * tuple.x + tuple.y
			* tuple.y + tuple.z * tuple.z + tuple.w * tuple.w));
}

t_tuple	tuple_normalization(t_tuple tuple)
{
	return ((t_tuple){tuple.x / tuple_magnitude(tuple),
		tuple.y / tuple_magnitude(tuple),
		tuple.z / tuple_magnitude(tuple),
		tuple.w / tuple_magnitude(tuple)});
}

double	dot_product(t_tuple tuple1, t_tuple tuple2)
{
	return (tuple1.x * tuple2.x + tuple1.y
		* tuple2.y + tuple1.z * tuple2.z + tuple1.w * tuple2.w);
}

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	return (set_vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}
