/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:23:49 by njooris           #+#    #+#             */
/*   Updated: 2025/09/25 16:51:04 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix4_ptr	matrix4_multiplication(t_matrix4 m1, t_matrix4 m2, t_matrix4 m3)
{
	int			x;
	int			y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			m3[x][y] = (m1[x][0] * m2[0][y])
				+ (m1[x][1] * m2[1][y])
				+ (m1[x][2] * m2[2][y])
				+ (m1[x][3] * m2[3][y]);
			y++;
		}
		x++;
	}
	return (m3);
}

t_matrix4_ptr	matrix3_multiplication(t_matrix3 m1, t_matrix3 m2, t_matrix4 m3)
{
	int	x;
	int	y;

	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			m3[x][y] = (m1[x][0] * m2[0][y])
				+ (m1[x][1] * m2[1][y])
				+ (m1[x][2] * m2[2][y]);
			y++;
		}
		x++;
	}
	return (m3);
}

t_matrix4_ptr	matrix2_multiplication(t_matrix2 m1, t_matrix2 m2, t_matrix4 m3)
{
	int	x;
	int	y;

	x = 0;
	while (x < 2)
	{
		y = 0;
		while (y < 2)
		{
			m3[x][y] = (m1[x][0] * m2[0][y])
				+ (m1[x][1] * m2[1][y]);
			y++;
		}
		x++;
	}
	return (m3);
}

t_tuple	matrix4_multiplication_by_tuple(t_matrix4 m1, t_tuple t1)
{
	t_tuple		t2;

	t2.x = (m1[0][0] * t1.x) + (m1[0][1] * t1.y)
		+ (m1[0][2] * t1.z) + (m1[0][3] * t1.w);
	t2.y = (m1[1][0] * t1.x) + (m1[1][1] * t1.y)
		+ (m1[1][2] * t1.z) + (m1[1][3] * t1.w);
	t2.z = (m1[2][0] * t1.x) + (m1[2][1] * t1.y)
		+ (m1[2][2] * t1.z) + (m1[2][3] * t1.w);
	t2.w = (m1[3][0] * t1.x) + (m1[3][1] * t1.y)
		+ (m1[3][2] * t1.z) + (m1[3][3] * t1.w);
	return (t2);
}
