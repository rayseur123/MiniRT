//
// Created by dernst on 9/23/25.
//

#include "../includes/scene.h"
#include <math.h>

t_tuple set_point(double const x, double const y, double const z)
{
	t_tuple point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;
	return (point);
};

t_tuple set_vector(double const x, double const y, double const z)
{
	t_tuple vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0.0;
	return (vector);
};

t_tuple	add_tuple(t_tuple t1, t_tuple const t2)
{
	t1.x = t1.x + t2.x;
	t1.y = t1.y + t2.y;
	t1.z = t1.z + t2.z;
	t1.w = t1.w + t2.w;
	return (t1);
}

t_tuple sub_tuple(t_tuple t1, t_tuple const t2)
{
	t1.x = t1.x - t2.x;
	t1.y = t1.y - t2.y;
	t1.z = t1.z - t2.z;
	t1.w = t1.w - t2.w;
	return (t1);
}

t_tuple neg_tuple(t_tuple tuple)
{
	tuple.x *= -1;
	tuple.y *= -1;
	tuple.z *= -1;
	tuple.w *= -1;
	return (tuple);
}

t_tuple multiplication_tuple(t_tuple tuple, double scale)
{
	tuple.x *= scale;
	tuple.y *= scale;
	tuple.z *= scale;
	tuple.w *= (u_int8_t)scale;
	return (tuple);
}

t_tuple divide_tuple(t_tuple tuple, double divide)
{
	if (divide == 0)
		return (tuple);
	tuple.x /= divide;
	tuple.y /= divide;
	tuple.z /= divide;
	tuple.w /= (uint8_t)divide;
	return (tuple);
}

double magnitude_tuple(t_tuple const tuple) {
	return (sqrt(tuple.x * tuple.x) + (tuple.y * tuple.y) + (tuple.z * tuple.z) + tuple.w * tuple.w);
}

t_tuple normalise_tuple(t_tuple tuple)
{
	double mag;

	mag = magnitude_tuple(tuple);
	tuple.x /= mag;
	tuple.y /= mag;
	tuple.z /= mag;
	tuple.w /= (uint8_t)mag;
	return (tuple);
}

double dot_tuple(const t_tuple t1, const t_tuple t2) {
	return ((t1.x * t2.x) + (t1.y * t2.y) + (t1.z * t2.z) + (t1.w * t2.w));
}

t_tuple cross_tuple(const t_tuple t1, const t_tuple t2) {
	t_tuple new;

	new.x = t1.y * t2.z - t1.z * t2.y;
	new.y = t1.z * t2.x - t1.x * t2.z;
	new.z = t1.x * t2.y - t1.y * t2.x;
	new.w = (uint8_t)0.0;
	return (new);
}

