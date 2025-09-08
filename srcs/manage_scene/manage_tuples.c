/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tuples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:41:52 by njooris           #+#    #+#             */
/*   Updated: 2025/09/04 13:13:02 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

t_tuple	set_vector(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 1;
	return (tuple);
}

t_tuple	set_point(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 0;
	return (tuple);
}

int	check_equal_tuples(t_tuple tuple1, t_tuple tuple2)
{
	return ((double_is_equal(tuple1.x, tuple2.x)
			&& double_is_equal(tuple1.y, tuple2.y)
			&& double_is_equal(tuple1.z, tuple2.z)));
}

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

t_tuple	tuple_negation(t_tuple tuple)
{
	t_tuple	zero;

	zero = set_vector(0, 0, 0);
	return (tuple_subtraction(zero, tuple));
}

t_tuple	tuple_multiplication(t_tuple tuple1, double scale)
{
	tuple1.x *= scale;
	tuple1.y *= scale;
	tuple1.z *= scale;
	return (tuple1);
}

t_tuple tuple_division(t_tuple tuple1, double scale)
{
    t_tuple result;
    if (scale == 0)
        return (tuple1);
    result.x = tuple1.x / scale;
    result.y = tuple1.y / scale;
    result.z = tuple1.z / scale;
    return (result);
}

double	tuple_magnitude(t_tuple tuple)
{
	return (sqrt(tuple.x * tuple.x + tuple.y * tuple.y + tuple.z * tuple.z + tuple.w));
}

t_tuple	tuple_normalization(t_tuple tuple)
{
	double magnitude;
	double inv_magnitude;

	magnitude = sqrt(tuple.x * tuple.x + tuple.y * tuple.y + tuple.z * tuple.z + tuple.w);
	inv_magnitude = 1.0 / magnitude;
	tuple.x *= inv_magnitude;
	tuple.y *= inv_magnitude;
	tuple.z *= inv_magnitude;
	tuple.w *= inv_magnitude;
	return (tuple);
}

int	dot_product(t_tuple tuple1, t_tuple tuple2)
{
	return (tuple1.x * tuple2.x + tuple1.y * tuple2.y + tuple1.z * tuple2.z + tuple1.w * tuple2.w);
}


t_tuple	cross_product(t_tuple a, t_tuple b)
{
	return (set_vector(a.y * b.z - a.z * b.y,
					   a.z * b.x - a.x * b.z,
					   a.x * b.y - a.y * b.x));
}

t_projectile	tick(t_environment env, t_projectile proj)
{
	t_projectile	proj2;
	proj2.position = tuple_addition(proj.position, proj.velocity);
	proj2.velocity = tuple_addition(tuple_addition(proj.velocity, env.gravity), env.wind);
	return (proj2);
}