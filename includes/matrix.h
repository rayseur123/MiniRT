/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:33:24 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 10:23:44 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by dernst on 10/9/25.
//

#ifndef MINIRT_MATRIX_H
#define MINIRT_MATRIX_H

#include <stdint.h>
#include "tuple.h"

#define IDENTITY_MTRX {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}

typedef double t_matrix4[4][4];
typedef double (*t_matrix4_ptr)[4];
typedef double t_matrix3[3][3];
typedef double (*t_matrix3_ptr)[3];
typedef double t_matrix2[2][2];
typedef double (*t_matrix2_ptr)[2];

uint8_t 		matrix4_is_equal(t_matrix4 m1, t_matrix4 m2);
uint8_t			matrix3_is_equal(t_matrix3 m1, t_matrix3 m2);
uint8_t 		matrix2_is_equal(t_matrix2 m1, t_matrix2 m2);
t_matrix3_ptr 	matrix4_submatrix(t_matrix4 m1, t_matrix3 m2, int row, int col);
t_matrix2_ptr 	matrix3_submatrix(t_matrix3 m1, t_matrix2 m2, int row, int col);
double 			determining_matrix2(t_matrix2 m);
double 			matrix3_minor(t_matrix3 m, int row, int col);
double 			matrix4_minor(t_matrix4 m, int row, int col);
t_matrix4_ptr 	matrix4_multiplication(t_matrix4 m1, t_matrix4 m2, t_matrix4 m3);
t_matrix4_ptr 	matrix3_multiplication(t_matrix3 m1, t_matrix3 m2, t_matrix4 m3);
t_tuple 		matrix4_multiplication_by_tuple(t_matrix4 m1, t_tuple t1);
t_matrix4_ptr 	matrix2_multiplication(t_matrix2 m1, t_matrix2 m2, t_matrix4 m3);
t_matrix4_ptr 	matrix4_transposition(t_matrix4 m1);
t_matrix3_ptr 	matrix3_transposition(t_matrix3 m1);
t_matrix2_ptr 	matrix2_transposition(t_matrix2 m1);
double 			matrix3_cofactor(t_matrix3 m, int row, int col);
double 			matrix4_cofactor(t_matrix4 m, int row, int col);
double 			determining_matrix2(t_matrix2 m);
double 			determining_matrix3(t_matrix3 m);
double 			determining_matrix4(t_matrix4 m);
int 			matrix4_is_reversible(t_matrix4 m);
t_matrix4_ptr 	matrix4_inverse(t_matrix4 m1, t_matrix4 m2);
t_matrix4_ptr	set_identity_matrix(t_matrix4 m);
t_matrix4_ptr	matrix4_cpy(t_matrix4 m, t_matrix4 m2);

#endif //MINIRT_MATRIX_H