/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:50:45 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 09:41:24 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	test_matrix4_equal_identical(void)
{
	t_matrix4 m1 = {{1, 2, 3, 4}, {5.5, 6.5, 7.5, 8.5}, {9, 10, 11, 12}, {13.5, 14.5, 15.5, 16.5}};
	t_matrix4 m2 = {{1, 2, 3, 4}, {5.5, 6.5, 7.5, 8.5}, {9, 10, 11, 12}, {13.5, 14.5, 15.5, 16.5}};

	if (!matrix4_is_equal(m1, m2))
		return (0);
	return (1);
}

int	test_matrix4_equal_different(void)
{
	t_matrix4 m1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	t_matrix4 m2 = {{2, 3, 4, 5}, {6, 7, 8, 9}, {10, 11, 12, 13}, {14, 15, 16, 17}};

	if (matrix4_is_equal(m1, m2))
		return (0);
	return (1);
}

int	test_matrix4_equal_small_difference(void)
{
	t_matrix4 m1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	t_matrix4 m2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16.00001}};

	if (!matrix4_is_equal(m1, m2))
		return (0);
	return (1);
}

int	test_matrix3_equal_identical(void)
{
	t_matrix3 m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	t_matrix3 m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	if (!matrix3_is_equal(m1, m2))
		return (0);
	return (1);
}

int	test_matrix3_equal_different(void)
{
	t_matrix3 m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	t_matrix3 m2 = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};

	if (matrix3_is_equal(m1, m2))
		return (0);
	return (1);
}

int	test_matrix3_equal_small_difference(void)
{
	t_matrix3 m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	t_matrix3 m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9.00001}};

	if (!matrix3_is_equal(m1, m2))
		return (0);
	return (1);
}

int	test_matrix2_equal_identical(void)
{
	t_matrix2 m1 = {{1, 2}, {3, 4}};
	t_matrix2 m2 = {{1, 2}, {3, 4}};

	if (!matrix2_is_equal(m1, m2))
		return (0);
	return (1);
}

int	test_matrix2_equal_different(void)
{
	t_matrix2 m1 = {{1, 2}, {3, 4}};
	t_matrix2 m2 = {{2, 3}, {4, 5}};

	if (matrix2_is_equal(m1, m2))
		return (0);
	return (1);
}

int	test_matrix2_equal_small_difference(void)
{
	t_matrix2 m1 = {{1, 2}, {3, 4}};
	t_matrix2 m2 = {{1, 2}, {3, 4.00001}};

	if (!matrix2_is_equal(m1, m2))
		return (0);
	return (1);
}

