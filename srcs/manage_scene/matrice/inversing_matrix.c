/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversing_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 05:08:27 by njooris           #+#    #+#             */
/*   Updated: 2025/09/30 13:21:57 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	matrix4_is_reversible(t_matrix4 m)
{
	return (!double_is_equal(determining_matrix4(m), 0));
}

t_matrix4_ptr	matrix4_cpy(t_matrix4 m, t_matrix4 m2)
{
	m[0][0] = m2[0][0];
	m[0][1] = m2[0][1];
	m[0][2] = m2[0][2];
	m[0][3] = m2[0][3];
	m[1][0] = m2[1][0];
	m[1][1] = m2[1][1];
	m[1][2] = m2[1][2];
	m[1][3] = m2[1][3];
	m[2][0] = m2[2][0];
	m[2][1] = m2[2][1];
	m[2][2] = m2[2][2];
	m[2][3] = m2[2][3];
	m[3][0] = m2[3][0];
	m[3][1] = m2[3][1];
	m[3][2] = m2[3][2];
	m[3][3] = m2[3][3];
	return (m);
}

t_matrix4_ptr	matrix4_inverse(t_matrix4 m1, t_matrix4 m2)
{
	double	deter;
	int		i;
	int		j;

	if (!matrix4_is_reversible(m1))
	{
		matrix4_cpy(m1, m2);
		return (m1);
	}
	deter = 1.0 / determining_matrix4(m1);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m2[i][j] = matrix4_cofactor(m1, j, i) * deter;
			j++;
		}
		i++;
	}
	return (m2);
}
