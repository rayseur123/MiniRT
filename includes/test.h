/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:50:43 by njooris           #+#    #+#             */
/*   Updated: 2025/09/30 13:38:54 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

// matrix.c 

int	test_matrix4_equal_identical(void);
int	test_matrix4_equal_small_difference(void);
int	test_matrix4_equal_different(void);
int	test_matrix3_equal_different(void);
int test_matrix3_equal_identical(void);
int	test_matrix3_equal_small_difference(void);
int	test_matrix2_equal_identical(void);
int	test_matrix2_equal_different(void);
int	test_matrix2_equal_small_difference(void);
int	test_matrix4_submatrice(void);
int	test_matrix3_submatrice(void);
int	test_matrix2_determining(void);
int	test_matrix3_determining(void);
int	test_matrix4_determining(void);
int	test_matrix3_minor(void);
int	test_matrix4_transposing(void);
int	test_matrix3_transposing(void);
int	test_matrix2_transposing(void);
int test_matrix3_cofactor(void);
int	test_matrix_inversing(void);

// tuples.c


int	test_set_vector(void);
int	test_set_point(void);
int	test_tuple_equality_positive(void);
int	test_tuple_inequality_positive(void);
int	test_tuple_equality_negative(void);
int	test_tuple_inequality_negative(void);
int	test_tuple_equality_mixed(void);
int	test_tuple_inequality_mixed(void);
int	test_addition_point_vector_positive(void);
int	test_addition_point_vector_negative(void);
int	test_addition_vector_vector_positive(void);
int	test_addition_vector_vector_negative(void);
int	test_addition_point_point_positive(void);
int	test_addition_point_point_negative(void);
int	test_subtraction_point_vector_positive(void);
int	test_subtraction_point_vector_negative(void);
int	test_subtraction_vector_vector_positive(void);
int	test_subtraction_vector_vector_negative(void);
int	test_subtraction_point_point_positive(void);
int	test_subtraction_point_point_negative(void);
int	test_negetion_positive(void);
int	test_negetion_negative(void);
int	test_negetion_mixe(void);
int test_multiplication_vector_positive(void);
int test_multiplication_vector_negative(void);
int test_multiplication_zero(void);
int test_division_vector_positive(void);
int test_division_vector_negative(void);
int test_division_vector_by_decimal(void);
int	test_magnitude_unit_vectors(void);
int	test_magnitude_positive_vectors(void);
int	test_magnitude_negative_vectors(void);
int	test_magnitude_zero_vector(void);
int	test_magnitude_points(void);
int	test_normalization_vector_positive(void);
int	test_normalization_vector_negative(void);
int	test_normalization_unit_vectors(void);
int	test_normalization_point_positive(void);
int	test_normalization_point_negative(void);
int	test_dot_product_vectors_positive(void);
int	test_dot_product_vectors_negative(void);
int	test_dot_product_orthogonal_vectors(void);
int	test_dot_product_zero_vector(void);
int	test_dot_product_points(void);
int	test_dot_product_mixed_types(void);
int	test_cross_product_basic_vectors(void);
int	test_cross_product_unit_vectors(void);
int	test_cross_product_anticommutative(void);
int	test_cross_product_parallel_vectors(void);
int	test_cross_product_zero_vector(void);
int	test_tick_basic_movement(void);
int	test_tick_no_forces(void);
int	test_tick_strong_forces(void);

// transformation

int	test_translation_tuple(void);
int	test_translation_inverse_mtrx(void);
int	test_translation_vector(void);
int	test_scaling_to_point(void);
int	test_scaling_to_vector(void);
int	test_scaling_to_matrix_inverse(void);
int	test_rotation_x(void);
int	test_rotation_y(void);
int	test_rotation_z(void);

// ray

int	test_ray_position(void);
int test_intersect_sphere_1(void);
int test_intersect_sphere_2(void);
int test_intersect_sphere_3(void);
int test_intersect_sphere_4(void);
int	test_set_intersection(void);
int test_aggregating_intersection(void);
int test_intersection_objet(void);
int	test_hit_1(void);
int	test_hit_2(void);
int	test_hit_3(void);
int	test_transfrom_1(void);
int	test_transfrom_2(void);
int	test_transfrom_3(void);
int	test_transfrom_4(void);
int	test_transfrom_5(void);
int	test_transfrom_6(void);

#endif