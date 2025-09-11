/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:22:50 by njooris           #+#    #+#             */
/*   Updated: 2025/09/08 14:51:32 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

int	test_set_vector(void)
{
	t_tuple tuple;

	tuple = set_vector(0, 0, 0);
	if (tuple.w == 0)
		return (0);
	return (1);
}

int	test_set_point(void)
{
	t_tuple tuple;

	tuple = set_point(0, 0, 0);
	if (tuple.w == 1)
		return (0);
	return (1);
}

int	test_tuple_equality_positive(void)
{
	t_tuple tuple1;
	t_tuple	tuple2;

	tuple1 = set_point(1, 1, 1);
	tuple2 = set_point(1, 1, 1);
	if (!check_equal_tuples(tuple1, tuple2))
		return (1);
	tuple1 = set_point(87, 12, 15);
	tuple2 = set_point(87, 12, 15);
	if (!check_equal_tuples(tuple1, tuple2))
		return (1);
	return (0);
}

int	test_tuple_inequality_positive(void)
{
	t_tuple tuple1;
	t_tuple	tuple2;

	tuple1 = set_point(1, 1, 1);
	tuple2 = set_point(2, 2, 2);
	if (check_equal_tuples(tuple1, tuple2))
		return (1);
	tuple1 = set_point(87, 12, 15);
	tuple2 = set_point(88, 13, 16);
	if (check_equal_tuples(tuple1, tuple2))
		return (1);
	return (0);
}

int	test_tuple_equality_negative(void)
{
	t_tuple tuple1;
	t_tuple	tuple2;

	tuple1 = set_point(-1, -1, -1);
	tuple2 = set_point(-1, -1, -1);
	if (!check_equal_tuples(tuple1, tuple2))
		return (1);
	tuple1 = set_point(-87, -12, -15);
	tuple2 = set_point(-87, -12, -15);
	if (!check_equal_tuples(tuple1, tuple2))
		return (1);
	return (0);
}

int	test_tuple_inequality_negative(void)
{
	t_tuple tuple1;
	t_tuple	tuple2;

	tuple1 = set_point(-1, -1, -1);
	tuple2 = set_point(-2, -2, -2);
	if (check_equal_tuples(tuple1, tuple2))
		return (1);
	tuple1 = set_point(-87, -12, -15);
	tuple2 = set_point(-88, -13, -16);
	if (check_equal_tuples(tuple1, tuple2))
		return (1);
	return (0);
}

int	test_tuple_equality_mixed(void)
{
	t_tuple tuple1;
	t_tuple	tuple2;

	tuple1 = set_point(-1, 1, -1);
	tuple2 = set_point(-1, 1, -1);
	if (!check_equal_tuples(tuple1, tuple2))
		return (1);
	tuple1 = set_point(87, -12, 15);
	tuple2 = set_point(87, -12, 15);
	if (!check_equal_tuples(tuple1, tuple2))
		return (1);
	return (0);
}

int	test_tuple_inequality_mixed(void)
{
	t_tuple tuple1;
	t_tuple	tuple2;

	tuple1 = set_point(-1, 1, -1);
	tuple2 = set_point(1, -1, 1);
	if (check_equal_tuples(tuple1, tuple2))
		return (1);
	tuple1 = set_point(87, -12, 15);
	tuple2 = set_point(-87, 12, -15);
	if (check_equal_tuples(tuple1, tuple2))
		return (1);
	return (0);
}

int	test_addition_point_vector_positive(void)
{
	t_tuple point;
	t_tuple	vector;
	t_tuple	result;

	point = set_point(1, 1, 1);
	vector = set_vector(1, 1, 1);
	result = tuple_addition(point, vector);
	if (result.x != 2 || result.y != 2 || result.z != 2 || result.w != 1)
		return (1);
	point = set_point(87, 87, 87);
	vector = set_vector(13, 13, 13);
	result = tuple_addition(point, vector);
	if (result.x != 100 || result.y != 100 || result.z != 100 || result.w != 1)
		return (1);
	return (0);
}

int	test_addition_point_vector_negative(void)
{
	t_tuple point;
	t_tuple	vector;
	t_tuple	result;

	point = set_point(-1, -1, -1);
	vector = set_vector(-1, -1, -1);
	result = tuple_addition(point, vector);
	if (result.x != -2 || result.y != -2 || result.z != -2 || result.w != 1)
		return (1);
	point = set_point(-87, -87, -87);
	vector = set_vector(-13, -13, -13);
	result = tuple_addition(point, vector);
	if (result.x != -100 || result.y != -100 || result.z != -100 || result.w != 1)
		return (1);
	return (0);
}

int	test_addition_vector_vector_positive(void)
{
	t_tuple vector1;
	t_tuple	vector2;
	t_tuple	result;

	vector1 = set_vector(1, 1, 1);
	vector2 = set_vector(1, 1, 1);
	result = tuple_addition(vector1, vector2);
	if (result.x != 2 || result.y != 2 || result.z != 2 || result.w != 0)
		return (1);
	vector1 = set_vector(87, 87, 87);
	vector2 = set_vector(13, 13, 13);
	result = tuple_addition(vector1, vector2);
	if (result.x != 100 || result.y != 100 || result.z != 100 || result.w != 0)
		return (1);
	return (0);
}

int	test_addition_vector_vector_negative(void)
{
	t_tuple vector1;
	t_tuple	vector2;
	t_tuple	result;

	vector1 = set_vector(-1, -1, -1);
	vector2 = set_vector(-1, -1, -1);
	result = tuple_addition(vector1, vector2);
	if (result.x != -2 || result.y != -2 || result.z != -2 || result.w != 0)
		return (1);
	vector1 = set_vector(-87, -87, -87);
	vector2 = set_vector(-13, -13, -13);
	result = tuple_addition(vector1, vector2);
	if (result.x != -100 || result.y != -100 || result.z != -100 || result.w != 0)
		return (1);
	return (0);
}

int	test_addition_point_point_positive(void)
{
	t_tuple point1;
	t_tuple	point2;
	t_tuple	result;

	point1 = set_point(1, 1, 1);
	point2 = set_point(1, 1, 1);
	result = tuple_addition(point1, point2);
	if (result.x != 2 || result.y != 2 || result.z != 2 || result.w != 2)
		return (1);
	point1 = set_point(87, 87, 87);
	point2 = set_point(13, 13, 13);
	result = tuple_addition(point1, point2);
	if (result.x != 100 || result.y != 100 || result.z != 100 || result.w != 2)
		return (1);
	return (0);
}

int	test_addition_point_point_negative(void)
{
	t_tuple point1;
	t_tuple	point2;
	t_tuple	result;

	point1 = set_point(-1, -1, -1);
	point2 = set_point(-1, -1, -1);
	result = tuple_addition(point1, point2);
	if (result.x != -2 || result.y != -2 || result.z != -2 || result.w != 2)
		return (1);
	point1 = set_point(-87, -87, -87);
	point2 = set_point(-13, -13, -13);
	result = tuple_addition(point1, point2);
	if (result.x != -100 || result.y != -100 || result.z != -100 || result.w != 2)
		return (1);
	return (0);
}

int	test_subtraction_point_vector_positive(void)
{
	t_tuple point;
	t_tuple	vector;
	t_tuple	result;

	point = set_point(1, 1, 1);
	vector = set_vector(1, 1, 1);
	result = tuple_subtraction(point, vector);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 1)
		return (1);
	point = set_point(87, 87, 87);
	vector = set_vector(17, 17, 17);
	result = tuple_subtraction(point, vector);
	if (result.x != 70 || result.y != 70 || result.z != 70 || result.w != 1)
		return (1);
	return (0);
}

int	test_subtraction_point_vector_negative(void)
{
	t_tuple point;
	t_tuple	vector;
	t_tuple	result;

	point = set_point(-1, -1, -1);
	vector = set_vector(-1, -1, -1);
	result = tuple_subtraction(point, vector);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 1)
		return (1);
	point = set_point(-87, -87, -87);
	vector = set_vector(-17, -17, -17);
	result = tuple_subtraction(point, vector);
	if (result.x != -70 || result.y != -70 || result.z != -70 || result.w != 1)
		return (1);
	return (0);
}

int	test_subtraction_vector_vector_positive(void)
{
	t_tuple vector1;
	t_tuple	vector2;
	t_tuple	result;

	vector1 = set_vector(1, 1, 1);
	vector2 = set_vector(1, 1, 1);
	result = tuple_subtraction(vector1, vector2);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	vector1 = set_vector(87, 87, 87);
	vector2 = set_vector(17, 17, 17);
	result = tuple_subtraction(vector1, vector2);
	if (result.x != 70 || result.y != 70 || result.z != 70 || result.w != 0)
		return (1);
	return (0);
}

int	test_subtraction_vector_vector_negative(void)
{
	t_tuple vector1;
	t_tuple	vector2;
	t_tuple	result;

	vector1 = set_vector(-1, -1, -1);
	vector2 = set_vector(-1, -1, -1);
	result = tuple_subtraction(vector1, vector2);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	vector1 = set_vector(-87, -87, -87);
	vector2 = set_vector(-17, -17, -17);
	result = tuple_subtraction(vector1, vector2);
	if (result.x != -70 || result.y != -70 || result.z != -70 || result.w != 0)
		return (1);
	return (0);
}

int	test_subtraction_point_point_positive(void)
{
	t_tuple point1;
	t_tuple	point2;
	t_tuple	result;

	point1 = set_point(1, 1, 1);
	point2 = set_point(1, 1, 1);
	result = tuple_subtraction(point1, point2);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	point1 = set_point(87, 87, 87);
	point2 = set_point(17, 17, 17);
	result = tuple_subtraction(point1, point2);
	if (result.x != 70 || result.y != 70 || result.z != 70 || result.w != 0)
		return (1);
	return (0);
}

int	test_subtraction_point_point_negative(void)
{
	t_tuple point1;
	t_tuple	point2;
	t_tuple	result;

	point1 = set_point(-1, -1, -1);
	point2 = set_point(-1, -1, -1);
	result = tuple_subtraction(point1, point2);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	point1 = set_point(-87, -87, -87);
	point2 = set_point(-17, -17, -17);
	result = tuple_subtraction(point1, point2);
	if (result.x != -70 || result.y != -70 || result.z != -70 || result.w != 0)
		return (1);
	return (0);
}

int	test_negetion_positive(void)
{
	t_tuple	tuple;
	t_tuple	negation_tuple;

	tuple = set_vector(10, 10, 10);
	negation_tuple = tuple_negation(tuple);
	if (negation_tuple.x != -10 || negation_tuple.y != -10 || negation_tuple.z != -10)
		return (1);
	tuple = set_vector(87, 87, 87);
	negation_tuple = tuple_negation(tuple);
	if (negation_tuple.x != -87 || negation_tuple.y != -87 || negation_tuple.z != -87)
		return (1);
	return (0);
}

int	test_negetion_negative(void)
{
	t_tuple	tuple;
	t_tuple	negation_tuple;

	tuple = set_vector(-10, -10, -10);
	negation_tuple = tuple_negation(tuple);
	if (negation_tuple.x != 10 || negation_tuple.y != 10 || negation_tuple.z != 10)
		return (1);
	tuple = set_vector(-87, -87, -87);
	negation_tuple = tuple_negation(tuple);
	if (negation_tuple.x != 87 || negation_tuple.y != 87 || negation_tuple.z != 87)
		return (1);
	return (0);
}

int	test_negetion_mixe(void)
{
	t_tuple	tuple;
	t_tuple	negation_tuple;

	tuple = set_vector(-77, 77, 88);
	negation_tuple = tuple_negation(tuple);
	if (negation_tuple.x != 77 || negation_tuple.y != -77 || negation_tuple.z != -88)
		return (1);
	tuple = set_vector(-87, 87, -87);
	negation_tuple = tuple_negation(tuple);
	if (negation_tuple.x != 87 || negation_tuple.y != -87 || negation_tuple.z != 87)
		return (1);
	return (0);
}

int test_multiplication_vector_positive(void)
{
    t_tuple vector;
    t_tuple result;

    vector = set_vector(1, 1, 1);
    result = tuple_multiplication(vector, 2);
    if (result.x != 2 || result.y != 2 || result.z != 2)
        return (1);
    vector = set_vector(10, 20, 30);
    result = tuple_multiplication(vector, 5);
    if (result.x != 50 || result.y != 100 || result.z != 150)
        return (1);
    return (0);
}

int test_multiplication_vector_negative(void)
{
    t_tuple vector;
    t_tuple result;

    vector = set_vector(-1, -1, -1);
    result = tuple_multiplication(vector, 2);
    if (result.x != -2 || result.y != -2 || result.z != -2)
        return (1);
    vector = set_vector(10, -20, 30);
    result = tuple_multiplication(vector, -5);
    if (result.x != -50 || result.y != 100 || result.z != -150)
        return (1);
    return (0);
}

int test_multiplication_zero(void)
{
    t_tuple point;
    t_tuple vector;
    t_tuple result_point;
    t_tuple result_vector;

    point = set_point(10, 20, 30);
    result_point = tuple_multiplication(point, 0);
    if (result_point.x != 0 || result_point.y != 0 || result_point.z != 0)
        return (1);
    vector = set_vector(10, 20, 30);
    result_vector = tuple_multiplication(vector, 0);
    if (result_vector.x != 0 || result_vector.y != 0 || result_vector.z != 0)
        return (1);
    return (0);
}

int test_division_vector_positive(void)
{
    t_tuple vector;
    t_tuple result;

    vector = set_vector(10, 20, 30);
    result = tuple_division(vector, 2);
    if (result.x != 5 || result.y != 10 || result.z != 15)
        return (1);
    vector = set_vector(100, 100, 100);
    result = tuple_division(vector, 10);
    if (result.x != 10 || result.y != 10 || result.z != 10 )
        return (1);
    return (0);
}

int test_division_vector_negative(void)
{
    t_tuple vector;
    t_tuple result;

    vector = set_vector(-10, -20, -30);
    result = tuple_division(vector, 2);
    if (result.x != -5 || result.y != -10 || result.z != -15 || result.w != 0)
        return (1);
    vector = set_vector(-100, 100, -100);
    result = tuple_division(vector, -10);
    if (result.x != 10 || result.y != -10 || result.z != 10 || result.w != 0)
        return (1);
    return (0);
}

int test_division_vector_by_decimal(void)
{
    t_tuple vector;
    t_tuple result;

    vector = set_vector(1, 1, 1);
    result = tuple_division(vector, 0.5);
    if (result.x != 2 || result.y != 2 || result.z != 2 || result.w != 0)
        return (1);
    vector = set_vector(50, 50, 50);
    result = tuple_division(vector, 2.5);
    if (result.x != 20 || result.y != 20 || result.z != 20 || result.w != 0)
        return (1);
    return (0);
}

int	test_magnitude_unit_vectors(void)
{
	t_tuple vector;
	double result;

	vector = set_vector(1, 0, 0);
	result = tuple_magnitude(vector);
	if (result != 1.0)
		return (1);
	vector = set_vector(0, 1, 0);
	result = tuple_magnitude(vector);
	if (result != 1.0)
		return (1);
	vector = set_vector(0, 0, 1);
	result = tuple_magnitude(vector);
	if (result != 1.0)
		return (1);
	return (0);
}

int	test_magnitude_positive_vectors(void)
{
	t_tuple vector;
	double result;

	vector = set_vector(1, 2, 3);
	result = tuple_magnitude(vector);
	if (result != sqrt(14))
		return (1);
	vector = set_vector(3, 4, 5);
	result = tuple_magnitude(vector);
	if (result != sqrt(50))
		return (1);
	return (0);
}

int	test_magnitude_negative_vectors(void)
{
	t_tuple vector;
	double result;

	vector = set_vector(-1, -2, -3);
	result = tuple_magnitude(vector);
	if (result != sqrt(14))
		return (1);
	vector = set_vector(-3, -4, -5);
	result = tuple_magnitude(vector);
	if (result != sqrt(50))
		return (1);
	return (0);
}

int	test_magnitude_zero_vector(void)
{
	t_tuple vector;
	double result;

	vector = set_vector(0, 0, 0);
	result = tuple_magnitude(vector);
	if (result != 0.0)
		return (1);
	return (0);
}

int	test_magnitude_points(void)
{
	t_tuple point;
	double result;

	point = set_point(1, 2, 3);
	result = tuple_magnitude(point);
	if (result != sqrt(15))
		return (1);
	point = set_point(0, 0, 0);
	result = tuple_magnitude(point);
	if (result != 1.0)
		return (1);
	return (0);
}

int	test_normalization_vector_positive(void)
{
	t_tuple vector;
	t_tuple result;
	double magnitude;

	vector = set_vector(4, 0, 0);
	result = tuple_normalization(vector);
	if (result.x != 1.0 || result.y != 0.0 || result.z != 0.0 || result.w != 0.0)
		return (1);
	
	vector = set_vector(1, 2, 3);
	result = tuple_normalization(vector);
	magnitude = tuple_magnitude(result);
	if (fabs(magnitude - 1.0) > 0.00001)
		return (1);
	return (0);
}

int	test_normalization_vector_negative(void)
{
	t_tuple vector;
	t_tuple result;
	double magnitude;

	vector = set_vector(-4, 0, 0);
	result = tuple_normalization(vector);
	if (result.x != -1.0 || result.y != 0.0 || result.z != 0.0 || result.w != 0.0)
		return (1);
	
	vector = set_vector(-1, -2, -3);
	result = tuple_normalization(vector);
	magnitude = tuple_magnitude(result);
	if (fabs(magnitude - 1.0) > 0.00001)
		return (1);
	return (0);
}

int	test_normalization_unit_vectors(void)
{
	t_tuple vector;
	t_tuple result;

	vector = set_vector(1, 0, 0);
	result = tuple_normalization(vector);
	if (result.x != 1.0 || result.y != 0.0 || result.z != 0.0 || result.w != 0.0)
		return (1);
	
	vector = set_vector(0, 1, 0);
	result = tuple_normalization(vector);
	if (result.x != 0.0 || result.y != 1.0 || result.z != 0.0 || result.w != 0.0)
		return (1);
	
	vector = set_vector(0, 0, 1);
	result = tuple_normalization(vector);
	if (result.x != 0.0 || result.y != 0.0 || result.z != 1.0 || result.w != 0.0)
		return (1);
	return (0);
}

int	test_dot_product_vectors_positive(void)
{
	t_tuple vector1;
	t_tuple vector2;
	int result;

	vector1 = set_vector(1, 2, 3);
	vector2 = set_vector(2, 3, 4);
	result = dot_product(vector1, vector2);
	if (result != 20)
		return (1);
	vector1 = set_vector(1, 0, 0);
	vector2 = set_vector(1, 0, 0);
	result = dot_product(vector1, vector2);
	if (result != 1)
		return (1);
	return (0);
}

int	test_dot_product_vectors_negative(void)
{
	t_tuple vector1;
	t_tuple vector2;
	int result;

	vector1 = set_vector(-1, -2, -3);
	vector2 = set_vector(-2, -3, -4);
	result = dot_product(vector1, vector2);
	if (result != 20)
		return (1);
	
	vector1 = set_vector(1, 2, 3);
	vector2 = set_vector(-1, -2, -3);
	result = dot_product(vector1, vector2);
	if (result != -14)
		return (1);
	return (0);
}

int	test_dot_product_orthogonal_vectors(void)
{
	t_tuple vector1;
	t_tuple vector2;
	int result;

	vector1 = set_vector(1, 0, 0);
	vector2 = set_vector(0, 1, 0);
	result = dot_product(vector1, vector2);
	if (result != 0)
		return (1);
	
	vector1 = set_vector(1, 1, 0);
	vector2 = set_vector(-1, 1, 0);
	result = dot_product(vector1, vector2);
	if (result != 0)
		return (1);
	return (0);
}

int	test_dot_product_zero_vector(void)
{
	t_tuple vector1;
	t_tuple vector2;
	int result;

	vector1 = set_vector(1, 2, 3);
	vector2 = set_vector(0, 0, 0);
	result = dot_product(vector1, vector2);
	if (result != 0)
		return (1);
	
	vector1 = set_vector(0, 0, 0);
	vector2 = set_vector(0, 0, 0);
	result = dot_product(vector1, vector2);
	if (result != 0)
		return (1);
	return (0);
}

int	test_dot_product_points(void)
{
	t_tuple point1;
	t_tuple point2;
	int result;

	point1 = set_point(1, 2, 3);
	point2 = set_point(2, 3, 4);
	result = dot_product(point1, point2);
	if (result != 21)
		return (1);
	
	point1 = set_point(0, 0, 0);
	point2 = set_point(1, 2, 3);
	result = dot_product(point1, point2);
	if (result != 1)
		return (1);
	return (0);
}

int	test_dot_product_mixed_types(void)
{
	t_tuple point;
	t_tuple vector;
	int result;

	point = set_point(1, 2, 3);
	vector = set_vector(2, 3, 4);
	result = dot_product(point, vector);
	if (result != 20)
		return (1);
	
	point = set_point(5, 5, 5);
	vector = set_vector(1, 1, 1);
	result = dot_product(point, vector);
	if (result != 15)
		return (1);
	return (0);
}

int	test_cross_product_basic_vectors(void)
{
	t_tuple vector1;
	t_tuple vector2;
	t_tuple result;

	vector1 = set_vector(1, 2, 3);
	vector2 = set_vector(2, 3, 4);
	result = cross_product(vector1, vector2);
	if (result.x != -1 || result.y != 2 || result.z != -1 || result.w != 0)
		return (1);
	
	vector1 = set_vector(1, 0, 0);
	vector2 = set_vector(0, 1, 0);
	result = cross_product(vector1, vector2);
	if (result.x != 0 || result.y != 0 || result.z != 1 || result.w != 0)
		return (1);
	return (0);
}

int	test_cross_product_unit_vectors(void)
{
	t_tuple x_axis;
	t_tuple y_axis;
	t_tuple z_axis;
	t_tuple result;

	x_axis = set_vector(1, 0, 0);
	y_axis = set_vector(0, 1, 0);
	z_axis = set_vector(0, 0, 1);

	result = cross_product(x_axis, y_axis);
	if (result.x != 0 || result.y != 0 || result.z != 1 || result.w != 0)
		return (1);
	
	result = cross_product(y_axis, z_axis);
	if (result.x != 1 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	
	result = cross_product(z_axis, x_axis);
	if (result.x != 0 || result.y != 1 || result.z != 0 || result.w != 0)
		return (1);
	return (0);
}

int	test_cross_product_anticommutative(void)
{
	t_tuple vector1;
	t_tuple vector2;
	t_tuple result1;
	t_tuple result2;

	vector1 = set_vector(1, 2, 3);
	vector2 = set_vector(2, 3, 4);
	
	result1 = cross_product(vector1, vector2);
	result2 = cross_product(vector2, vector1);
	
	if (result1.x != -result2.x || result1.y != -result2.y || result1.z != -result2.z)
		return (1);
	if (result1.w != 0 || result2.w != 0)
		return (1);
	return (0);
}

int	test_cross_product_parallel_vectors(void)
{
	t_tuple vector1;
	t_tuple vector2;
	t_tuple result;

	vector1 = set_vector(1, 2, 3);
	vector2 = set_vector(2, 4, 6);
	result = cross_product(vector1, vector2);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	
	vector1 = set_vector(1, 0, 0);
	vector2 = set_vector(3, 0, 0);
	result = cross_product(vector1, vector2);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	return (0);
}

int	test_cross_product_zero_vector(void)
{
	t_tuple vector1;
	t_tuple vector2;
	t_tuple result;

	vector1 = set_vector(1, 2, 3);
	vector2 = set_vector(0, 0, 0);
	result = cross_product(vector1, vector2);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	
	vector1 = set_vector(0, 0, 0);
	vector2 = set_vector(5, 6, 7);
	result = cross_product(vector1, vector2);
	if (result.x != 0 || result.y != 0 || result.z != 0 || result.w != 0)
		return (1);
	return (0);
}

int	test_tick_basic_movement(void)
{
	t_environment env;
	t_projectile proj;
	t_projectile result;

	env.gravity = set_vector(0, -0.1, 0);
	env.wind = set_vector(-0.01, 0, 0);
	proj.position = set_point(0, 1, 0);
	proj.velocity = set_vector(1, 1, 0);
	
	result = tick(env, proj);
	
	if (result.position.x != 1 || result.position.y != 2 || result.position.z != 0)
		return (1);
	if (result.velocity.x != 0.99 || result.velocity.y != 0.9 || result.velocity.z != 0)
		return (1);
	return (0);
}

int	test_tick_no_forces(void)
{
	t_environment env;
	t_projectile proj;
	t_projectile result;

	env.gravity = set_vector(0, 0, 0);
	env.wind = set_vector(0, 0, 0);
	proj.position = set_point(1, 2, 3);
	proj.velocity = set_vector(0.5, -0.5, 1);
	
	result = tick(env, proj);
	
	if (result.position.x != 1.5 || result.position.y != 1.5 || result.position.z != 4)
		return (1);
	if (result.velocity.x != 0.5 || result.velocity.y != -0.5 || result.velocity.z != 1)
		return (1);
	return (0);
}

int	test_tick_strong_forces(void)
{
	t_environment env;
	t_projectile proj;
	t_projectile result;

	env.gravity = set_vector(0, -10, 0);
	env.wind = set_vector(5, 0, -2);
	proj.position = set_point(0, 0, 0);
	proj.velocity = set_vector(1, 1, 1);
	
	result = tick(env, proj);
	
	if (result.position.x != 1 || result.position.y != 1 || result.position.z != 1)
		return (1);
	if (result.velocity.x != 6 || result.velocity.y != -9 || result.velocity.z != -1)
		return (1);
	return (0);
}
