/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_libs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:31:27 by dernst            #+#    #+#             */
/*   Updated: 2025/10/27 09:02:47 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "units.h"
#include "test.h"
#include <stdio.h>
void	lib_unit(void) {
	t_function *function;

	function = NULL;
	adding_test(&function, "Matrice", "matrix4_equal_different", &test_matrix4_equal_different);
	adding_test(&function, "Matrice", "matrix4_equal_small_difference", &test_matrix4_equal_small_difference);
	adding_test(&function, "Matrice", "matrix3_equal_identical", &test_matrix3_equal_identical);
	adding_test(&function, "Matrice", "matrix3_equal_different", &test_matrix3_equal_different);
	adding_test(&function, "Matrice", "matrix3_equal_small_difference", &test_matrix3_equal_small_difference);
	adding_test(&function, "Matrice", "matrix2_equal_identical", &test_matrix2_equal_identical);
	adding_test(&function, "Matrice", "matrix2_equal_different", &test_matrix2_equal_different);
	adding_test(&function, "Matrice", "matrix2_equal_small_difference", &test_matrix2_equal_small_difference);
	
	adding_test(&function, "Matrice", "matrix4_submatrice", &test_matrix4_submatrice);
	adding_test(&function, "Matrice", "matrix3_submatrice", &test_matrix3_submatrice);
	adding_test(&function, "Matrice", "matrix2_determining", &test_matrix2_determining);
	adding_test(&function, "Matrice", "matrix3_determining", &test_matrix3_determining);
	adding_test(&function, "Matrice", "matrix4_determining", &test_matrix4_determining);
	adding_test(&function, "Matrice", "matrix3_minor", &test_matrix3_minor);
	adding_test(&function, "Matrice", "matrix4_transposing", &test_matrix4_transposing);
	adding_test(&function, "Matrice", "matrix3_transposing", &test_matrix3_transposing);
	adding_test(&function, "Matrice", "matrix2_transposing", &test_matrix2_transposing);
	adding_test(&function, "Matrice", "matrix3_cofactor", &test_matrix3_cofactor);
	adding_test(&function, "Matrice", "matrix_inversing", &test_matrix_inversing);

	adding_test(&function, "Tuples", "set_vector", &test_set_vector);
	adding_test(&function, "Tuples", "set_point", &test_set_point);
	adding_test(&function, "Tuples", "tuple_equality_positive", &test_tuple_equality_positive);
	adding_test(&function, "Tuples", "tuple_inequality_positive", &test_tuple_inequality_positive);
	adding_test(&function, "Tuples", "tuple_equality_negative", &test_tuple_equality_negative);
	adding_test(&function, "Tuples", "tuple_inequality_negative", &test_tuple_inequality_negative);
	adding_test(&function, "Tuples", "tuple_equality_mixed", &test_tuple_equality_mixed);
	adding_test(&function, "Tuples", "tuple_inequality_mixed", &test_tuple_inequality_mixed);
	adding_test(&function, "Tuples", "addition_point_vector_positive", &test_addition_point_vector_positive);
	adding_test(&function, "Tuples", "addition_point_vector_negative", &test_addition_point_vector_negative);
	adding_test(&function, "Tuples", "addition_vector_vector_positive", &test_addition_vector_vector_positive);
	adding_test(&function, "Tuples", "addition_vector_vector_negative", &test_addition_vector_vector_negative);
	adding_test(&function, "Tuples", "addition_point_point_positive", &test_addition_point_point_positive);
	adding_test(&function, "Tuples", "addition_point_point_negative", &test_addition_point_point_negative);
	adding_test(&function, "Tuples", "subtraction_point_vector_positive", &test_subtraction_point_vector_positive);
	adding_test(&function, "Tuples", "subtraction_point_vector_negative", &test_subtraction_point_vector_negative);
	adding_test(&function, "Tuples", "subtraction_vector_vector_positive", &test_subtraction_vector_vector_positive);
	adding_test(&function, "Tuples", "subtraction_vector_vector_negative", &test_subtraction_vector_vector_negative);
	adding_test(&function, "Tuples", "subtraction_point_point_positive", &test_subtraction_point_point_positive);
	adding_test(&function, "Tuples", "subtraction_point_point_negative", &test_subtraction_point_point_negative);
	adding_test(&function, "Tuples", "negation_positive", &test_negetion_positive);
	adding_test(&function, "Tuples", "negation_negative", &test_negetion_negative);
	adding_test(&function, "Tuples", "negation_mixe", &test_negetion_mixe);
	adding_test(&function, "Tuples", "multiplication_vector_positive", &test_multiplication_vector_positive);
	adding_test(&function, "Tuples", "multiplication_vector_negative", &test_multiplication_vector_negative);
	adding_test(&function, "Tuples", "multiplication_zero", &test_multiplication_zero);
	adding_test(&function, "Tuples", "division_vector_positive", &test_division_vector_positive);
	adding_test(&function, "Tuples", "division_vector_negative", &test_division_vector_negative);
	adding_test(&function, "Tuples", "division_vector_by_decimal", &test_division_vector_by_decimal);
	adding_test(&function, "Tuples", "magnitude_unit_vectors", &test_magnitude_unit_vectors);
	adding_test(&function, "Tuples", "magnitude_positive_vectors", &test_magnitude_positive_vectors);
	adding_test(&function, "Tuples", "magnitude_negative_vectors", &test_magnitude_negative_vectors);
	adding_test(&function, "Tuples", "magnitude_zero_vector", &test_magnitude_zero_vector);
	adding_test(&function, "Tuples", "magnitude_points", &test_magnitude_points);
	adding_test(&function, "Tuples", "normalization_vector_positive", &test_normalization_vector_positive);
	adding_test(&function, "Tuples", "normalization_vector_negative", &test_normalization_vector_negative);
	adding_test(&function, "Tuples", "normalization_unit_vectors", &test_normalization_unit_vectors);
	adding_test(&function, "Tuples", "dot_product_vectors_positive", &test_dot_product_vectors_positive);
	adding_test(&function, "Tuples", "dot_product_vectors_negative", &test_dot_product_vectors_negative);
	adding_test(&function, "Tuples", "dot_product_orthogonal_vectors", &test_dot_product_orthogonal_vectors);
	adding_test(&function, "Tuples", "dot_product_zero_vector", &test_dot_product_zero_vector);
	adding_test(&function, "Tuples", "dot_product_points", &test_dot_product_points);
	adding_test(&function, "Tuples", "dot_product_mixed_types", &test_dot_product_mixed_types);
	adding_test(&function, "Tuples", "cross_product_basic_vectors", &test_cross_product_basic_vectors);
	adding_test(&function, "Tuples", "cross_product_unit_vectors", &test_cross_product_unit_vectors);
	adding_test(&function, "Tuples", "cross_product_anticommutative", &test_cross_product_anticommutative);
	adding_test(&function, "Tuples", "cross_product_parallel_vectors", &test_cross_product_parallel_vectors);
	adding_test(&function, "Tuples", "cross_product_zero_vector", &test_cross_product_zero_vector);
	adding_test(&function, "Tuples", "tick_basic_movement", &test_tick_basic_movement);
	adding_test(&function, "Tuples", "tick_no_forces", &test_tick_no_forces);
	adding_test(&function, "Tuples", "tick_strong_forces", &test_tick_strong_forces);
	
	adding_test(&function, "Trans", "translation_tuple", &test_translation_tuple);
	adding_test(&function, "Trans", "translation_inverse_mtrx", &test_translation_inverse_mtrx);
	adding_test(&function, "Trans", "translation_vector", &test_translation_vector);
	adding_test(&function, "Trans", "scaling_to_point", &test_scaling_to_point);
	adding_test(&function, "Trans", "scaling_to_vector", &test_scaling_to_vector);
	adding_test(&function, "Trans", "scaling_to_matrix_inverse", &test_scaling_to_matrix_inverse);
	adding_test(&function, "Trans", "rotation_x", &test_rotation_x);
	adding_test(&function, "Trans", "rotation_y", &test_rotation_y);
	adding_test(&function, "Trans", "rotation_z", &test_rotation_z);

	adding_test(&function, "Rays", "set_position", &test_ray_position);
	adding_test(&function, "Rays", "intersect_sphere_1", &test_intersect_sphere_1);
	adding_test(&function, "Rays", "intersect_sphere_2", &test_intersect_sphere_2);
	adding_test(&function, "Rays", "intersect_sphere_3", &test_intersect_sphere_3);
	adding_test(&function, "Rays", "intersect_sphere_4", &test_intersect_sphere_4);
	adding_test(&function, "Rays", "set_intersection", &test_set_intersection);
	adding_test(&function, "Rays", "intersection_aggregating", &test_aggregating_intersection);
	adding_test(&function, "Rays", "intersection_object", &test_intersection_objet);
	adding_test(&function, "Rays", "hit_1", &test_hit_1);
	adding_test(&function, "Rays", "hit_2", &test_hit_2);
	adding_test(&function, "Rays", "hit_3", &test_hit_3);
	adding_test(&function, "Rays", "transfrom_1", &test_transfrom_1);
	adding_test(&function, "Rays", "transfrom_2", &test_transfrom_2);
	adding_test(&function, "Rays", "transfrom_3", &test_transfrom_3);
	adding_test(&function, "Rays", "transfrom_4", &test_transfrom_4);
	adding_test(&function, "Rays", "transfrom_5", &test_transfrom_5);
	adding_test(&function, "Rays", "transfrom_6", &test_transfrom_6);
	adding_test(&function, "Rays", "normal_vector_on_sphere1", &test_normal_vector_on_sphere1);
	adding_test(&function, "Rays", "normal_vector_on_sphere2", &test_normal_vector_on_sphere2);
	adding_test(&function, "Rays", "normal_vector_on_sphere3", &test_normal_vector_on_sphere3);
	adding_test(&function, "Rays", "normal_vector_on_sphere4", &test_normal_vector_on_sphere4);
	adding_test(&function, "Rays", "normal_vector_on_sphere5", &test_normal_vector_on_sphere5);
	adding_test(&function, "Rays", "normal_vector_on_sphere6", &test_normal_vector_on_sphere6);
	adding_test(&function, "Rays", "normal_vector_on_sphere7", &test_normal_vector_on_sphere7);
	adding_test(&function, "Rays", "reflect_vector_on_sphere1", &test_reflect_vector_on_sphere1);
	adding_test(&function, "Rays", "reflect_vector_on_sphere2", &test_reflect_vector_on_sphere2);

	adding_test(&function, "Rgb", "set_rgb", &test_set_rgb);
	adding_test(&function, "Rgb", "rgb_addition", &test_rgb_addition);
	adding_test(&function, "Rgb", "rgb_subtraction", &test_rgb_subtraction);
	adding_test(&function, "Rgb", "rgb_multiplication_scalar", &test_rgb_multiplication_scalar);
	adding_test(&function, "Rgb", "rgb_multiplication", &test_rgb_multiplication);

	adding_test(&function, "Light", "create_light", &test_create_light);
	adding_test(&function, "Light", "default_material", &test_default_material);
	adding_test(&function, "Light", "light_btw_light_surface", &test_light_btw_light_surface);
	adding_test(&function, "Light", "light_btw_light_45", &test_light_btw_light_45);
	adding_test(&function, "Light", "light_btw_light_opposite_45", &test_light_btw_light_opposite_45);
	adding_test(&function, "Light", "light_btw_light_reflection", &test_light_btw_light_reflection);
	adding_test(&function, "Light", "light_light_behind_surface", &test_light_behind_surface);

	adding_test(&function, "World", "world_0", &test_world_0);
	adding_test(&function, "World", "world_1", &test_world_1);
	adding_test(&function, "World", "world_2", &test_world_2);
	adding_test(&function, "World", "world_3", &test_world_3);
	adding_test(&function, "World", "world_4", &test_world_4);
	adding_test(&function, "World", "world_5", &test_world_5);
	adding_test(&function, "World", "world_6", &test_world_6);
	// adding_test(&function, "World", "world_7", &test_world_7);
	// adding_test(&function, "World", "world_8", &test_world_8);
	// adding_test(&function, "World", "world_9", &test_world_9);

	adding_test(&function, "Camera", "camera_1", &test_camera_1);	
	adding_test(&function, "Camera", "camera_2", &test_camera_2);
	adding_test(&function, "Camera", "camera_3", &test_camera_3);
	adding_test(&function, "Camera", "camera_4", &test_camera_4);
	adding_test(&function, "Camera", "camera_5", &test_camera_5);
	adding_test(&function, "Camera", "camera_6", &test_camera_6);
	adding_test(&function, "Camera", "camera_7", &test_camera_7);
	adding_test(&function, "Camera", "camera_8", &test_camera_8);
	adding_test(&function, "Camera", "camera_9", &test_camera_9);
	adding_test(&function, "Camera", "camera_10", &test_camera_10);
	adding_test(&function, "Camera", "camera_11", &test_camera_11);

	adding_test(&function, "Object", "shape_1", &test_shape1);
	adding_test(&function, "Object", "shape_2", &test_shape2);
	adding_test(&function, "Object", "shape_3", &test_shape3);
	adding_test(&function, "Object", "shape_6", &test_shape6);
	adding_test(&function, "Object", "plane_0", &test_plane0);
	adding_test(&function, "Object", "plane_1", &test_plane1);
	adding_test(&function, "Object", "plane_2", &test_plane2);
	adding_test(&function, "Object", "plane_3", &test_plane3);
	adding_test(&function, "Object", "plane_4", &test_plane4);
	adding_test(&function, "Object", "plane_5", &test_plane5);

	adding_test(&function, "Shadow", "shadow_1", &test_shadow1);
	adding_test(&function, "Shadow", "shadow_2", &test_shadow2);
	adding_test(&function, "Shadow", "shadow_3", &test_shadow3);
	adding_test(&function, "Shadow", "shadow_4", &test_shadow4);
	adding_test(&function, "Shadow", "shadow_5", &test_shadow5);
	adding_test(&function, "Shadow", "shadow_6", &test_shadow6);
	adding_test(&function, "Shadow", "shadow_7", &test_shadow7);

	launch_lib_test(&function);
}
