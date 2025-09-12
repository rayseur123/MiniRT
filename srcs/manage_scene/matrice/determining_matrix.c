/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determining_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:21:37 by njooris           #+#    #+#             */
/*   Updated: 2025/09/12 04:44:18 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

double	determining_matrix2(t_matrix2 m)
{
	return ((m[0][0] * m[1][1]) + (m[1][0] * m[0][1]));
}

double	determining_matrix3(t_matrix3 m)
{
	return (m[0][0] * matrix3_cofactor(m, 0, 0)
		+ m[0][1] * matrix3_cofactor(m, 0, 1)
		+ m[0][2] * matrix3_cofactor(m, 0, 2));
}

double	determining_matrix4(t_matrix4 m)
{
	return (m[0][0] * matrix4_cofactor(m, 0, 0)
		+ m[0][1] * matrix4_cofactor(m, 0, 1)
		+ m[0][2] * matrix4_cofactor(m, 0, 2)
		+ m[0][3] * matrix4_cofactor(m, 0, 3));
}
