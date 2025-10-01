/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:50:45 by njooris           #+#    #+#             */
/*   Updated: 2025/09/25 15:29:05 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int test_matrix4_equal_identical(void)
{
	t_matrix4 m1 = {{1, 2, 3, 4}, {5.5, 6.5, 7.5, 8.5}, {9, 10, 11, 12}, {13.5, 14.5, 15.5, 16.5}};
	t_matrix4 m2 = {{1, 2, 3, 4}, {5.5, 6.5, 7.5, 8.5}, {9, 10, 11, 12}, {13.5, 14.5, 15.5, 16.5}};

	if (!matrix4_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix4_equal_different(void)
{
	t_matrix4 m1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	t_matrix4 m2 = {{2, 3, 4, 5}, {6, 7, 8, 9}, {10, 11, 12, 13}, {14, 15, 16, 17}};

	if (matrix4_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix4_equal_small_difference(void)
{
	t_matrix4 m1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	t_matrix4 m2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16.00001}};

	if (!matrix4_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix3_equal_identical(void)
{
	t_matrix3 m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	t_matrix3 m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	if (!matrix3_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix3_equal_different(void)
{
	t_matrix3 m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	t_matrix3 m2 = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};

	if (matrix3_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix3_equal_small_difference(void)
{
	t_matrix3 m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	t_matrix3 m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9.00001}};

	if (!matrix3_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix2_equal_identical(void)
{
	t_matrix2 m1 = {{1, 2}, {3, 4}};
	t_matrix2 m2 = {{1, 2}, {3, 4}};

	if (!matrix2_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix2_equal_different(void)
{
	t_matrix2 m1 = {{1, 2}, {3, 4}};
	t_matrix2 m2 = {{2, 3}, {4, 5}};

	if (matrix2_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix2_equal_small_difference(void)
{
	t_matrix2 m1 = {{1, 2}, {3, 4}};
	t_matrix2 m2 = {{1, 2}, {3, 4.00001}};

	if (!matrix2_is_equal(m1, m2))
		return (1);
	return (0);
}

int test_matrix4_submatrice(void)
{
	t_matrix4 m1 = {{-6, 1, 1, 6}, {-8, 5, 8, 6}, {-1, 0, 8, 2}, {-7, 1, -1, 1}};
	t_matrix3 m2 = {{-6, 1, 6}, {-8, 8, 6}, {-7, -1, 1}};
	t_matrix3 m3;

	matrix4_submatrix(m1, m3, 2, 1);
	if (!matrix3_is_equal(m3, m2))
		return (1);
	return (0);
}

int test_matrix3_submatrice(void)
{
	t_matrix3 m1 = {{1, 5, 0}, {-3, 2, 7}, {0, 6, -3}};
	t_matrix2 m2 = {{-3, 2}, {0, 6}};
	t_matrix2 m3;

	matrix3_submatrix(m1, m3, 0, 2);
	if (!matrix2_is_equal(m3, m2))
		return (1);
	return (0);
}

int test_matrix2_determining(void)
{
	t_matrix2 m1 = {{1, 5}, {-3, 2}};

	if (!double_is_equal(determining_matrix2(m1), 17))
		return (1);
	return (0);
}

int test_matrix3_determining(void)
{
	t_matrix3 m1 = {{1, 2, 6}, {-5, 8, -4}, {2, 6, 4}};

	if (!double_is_equal(determining_matrix3(m1), -196))
		return (1);
	return (0);
}

int test_matrix4_determining(void)
{
	t_matrix4 m1 = {{-2, -8, 3, 5}, {-3, 1, 7, 3}, {1, 2, -9, 6}, {-6, 7, 7, -9}};

	if (!double_is_equal(determining_matrix4(m1), -4071))
		return (1);
	return (0);
}

int test_matrix3_minor(void)
{
	t_matrix3 m1 = {{3, 5, 0}, {2, -1, -7}, {6, -1, 5}};
	t_matrix2	m2;
	
	matrix3_submatrix(m1, m2, 1, 0);
	if (!double_is_equal(determining_matrix2(m2), 25))
		return (1);
	if (!double_is_equal(matrix3_minor(m1, 1, 0), 25))
		return (1);
	return (0);
}

int test_matrix4_transposing(void)
{
	t_matrix4 m1 = {{0, 9, 3, 0}, {9, 8, 0, 8}, {1, 8, 5, 3}, {0, 0, 5, 8}};
	t_matrix4 m2 = {{0, 9, 1, 0}, {9, 8, 8, 0}, {3, 0, 5, 5}, {0, 8, 3, 8}};

	if (!matrix4_is_equal(matrix4_transposition(m1), m2))
		return (1);
	return (0);
}

int test_matrix3_transposing(void)
{
	t_matrix3 m1 = {{0, 9, 3}, {9, 8, 0}, {1, 8, 5}};
	t_matrix3 m2 = {{0, 9, 1}, {9, 8, 8}, {3, 0, 5}};

	if (!matrix3_is_equal(matrix3_transposition(m1), m2))
		return (1);
	return (0);
}

int test_matrix2_transposing(void)
{
	t_matrix2 m1 = {{0, 9}, {9, 8}};
	t_matrix2 m2 = {{0, 9}, {9, 8}};

	if (!matrix2_is_equal(matrix2_transposition(m1), m2))
		return (1);
	return (0);
}

int test_matrix3_cofactor(void)
{
	
	t_matrix3 m1 = {{3, 5, 0}, {2, -1, -7}, {6, -1, 5}};
	if (!double_is_equal(matrix3_cofactor(m1, 0, 0), -12))
		return (1);
	if (!double_is_equal(matrix3_cofactor(m1, 1, 0), -25))
		return (1);
	return (0);
}

int test_matrix_inversing(void)
{
	t_matrix4 m1 = {{-5, 2, 6, -8}, {1, -5, 1, 8}, {7, 7, -6, -7}, {1, -3, 7, 4}};
	t_matrix4 m2 = {{0.21805, 0.45113, 0.24060, -0.04511}, {-0.80827, -1.45677, -0.44361, 0.52068}, {-0.07895, -0.22368, -0.05263, 0.19737}, {-0.52256, -0.81391, -0.30075, 0.30639}};
	t_matrix4 m3;
	
	matrix4_inverse(m1, m3);
	if (!matrix4_is_equal(m2, m3))
		return (1);
	return (0);
}
