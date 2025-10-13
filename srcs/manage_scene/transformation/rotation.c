/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:50:34 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 10:49:20 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_matrix4_ptr	rotation_x(double radian, t_matrix4 m)
{
	set_identity_matrix(m);
	m[1][1] = cos(radian);
	m[1][2] = -sin(radian);
	m[2][1] = sin(radian);
	m[2][2] = cos(radian);
	return (m);
}

t_matrix4_ptr	rotation_y(double radian, t_matrix4 m)
{
	set_identity_matrix(m);
	m[0][0] = cos(radian);
	m[0][2] = sin(radian);
	m[2][0] = -sin(radian);
	m[2][2] = cos(radian);
	return (m);
}

t_matrix4_ptr	rotation_z(double radian, t_matrix4 m)
{
	set_identity_matrix(m);
	m[0][0] = cos(radian);
	m[0][1] = -sin(radian);
	m[1][0] = sin(radian);
	m[1][1] = cos(radian);
	return (m);
}
