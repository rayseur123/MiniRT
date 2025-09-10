/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:23:49 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 09:17:07 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

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
	int			x;
	int			y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		if (x == 0)
			t2.x = (m1[x][0] * t1.x) + (m1[x][1] * t1.y)
				+ (m1[x][2] * t1.z) + (m1[x][3] * t1.w);
		else if (x == 1)
			t2.y = (m1[x][0] * t1.x) + (m1[x][1] * t1.y)
				+ (m1[x][2] * t1.z) + (m1[x][3] * t1.w);
		else if (x == 2)
			t2.z = (m1[x][0] * t1.x) + (m1[x][1] * t1.y)
				+ (m1[x][2] * t1.z) + (m1[x][3] * t1.w);
		else if (x == 3)
			t2.w = (m1[x][0] * t1.x) + (m1[x][1] * t1.y)
				+ (m1[x][2] * t1.z) + (m1[x][3] * t1.w);
		x++;
	}
	return (t2);
}
