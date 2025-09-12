/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversing_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 05:08:27 by njooris           #+#    #+#             */
/*   Updated: 2025/09/12 05:47:42 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

int	matrix4_is_reversible(t_matrix4 m)
{
	return (!double_is_equal(determining_matrix4(m), 0));
}

t_matrix4_ptr	matrix4_reverse(t_matrix4 m1, t_matrix4 m2)
{
	double	deter;

	if (!matrix4_is_reversible(m1))
		return (m1);
	deter = 1.0 / determining_matrix4(m1);
	m2[0][0] = matrix4_cofactor(m1, 0, 0) * deter;
	m2[1][0] = matrix4_cofactor(m1, 0, 1) * deter;
	m2[2][0] = matrix4_cofactor(m1, 0, 2) * deter;
	m2[3][0] = matrix4_cofactor(m1, 0, 3) * deter;
	m2[0][1] = matrix4_cofactor(m1, 1, 0) * deter;
	m2[1][1] = matrix4_cofactor(m1, 1, 1) * deter;
	m2[2][1] = matrix4_cofactor(m1, 1, 2) * deter;
	m2[3][1] = matrix4_cofactor(m1, 1, 3) * deter;
	m2[0][2] = matrix4_cofactor(m1, 2, 0) * deter;
	m2[1][2] = matrix4_cofactor(m1, 2, 1) * deter;
	m2[2][2] = matrix4_cofactor(m1, 2, 2) * deter;
	m2[3][2] = matrix4_cofactor(m1, 2, 3) * deter;
	m2[0][3] = matrix4_cofactor(m1, 3, 0) * deter;
	m2[1][3] = matrix4_cofactor(m1, 3, 1) * deter;
	m2[2][3] = matrix4_cofactor(m1, 3, 2) * deter;
	m2[3][3] = matrix4_cofactor(m1, 3, 3) * deter;
	return (m2);
}