/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrice_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:37:06 by dernst            #+#    #+#             */
/*   Updated: 2025/11/18 10:34:15 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m2matrice_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:39:37 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 12:41:14 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix3_ptr	matrix4_submatrix(t_matrix4 m1, t_matrix3 m2, int row, int col)
{
	int	x2;
	int	x;
	int	y2;
	int	y;

	y2 = 0;
	y = -1;
	while (++y < 4)
	{
		if (y == row)
			continue ;
		x = -1;
		x2 = 0;
		while (++x < 4)
		{
			if (x == col)
				continue ;
			m2[y2][x2] = m1[y][x];
			++x2;
		}
		++y2;
	}
	return (m2);
}

t_matrix2_ptr	matrix3_submatrix(t_matrix3 m1, t_matrix2 m2, int row, int col)
{
	int	x2;
	int	x;
	int	y2;
	int	y;

	y2 = 0;
	y = -1;
	while (++y < 3)
	{
		if (y == row)
			continue ;
		x = -1;
		x2 = 0;
		while (++x < 3)
		{
			if (x == col)
				continue ;
			m2[y2][x2] = m1[y][x];
			++x2;
		}
		++y2;
	}
	return (m2);
}
