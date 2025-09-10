/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposition_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:43:09 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 11:34:28 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

t_matrix4_ptr	matrix4_transposition(t_matrix4 m1)
{
	int		i;
	int		j;
	double	buff;

	i = 0;
	while (i < 4)
	{
		j = i;
		while (j < 4)
		{
			buff = m1[i][j];
			m1[i][j] = m1[j][i];
			m1[j][i] = buff;
			j++;
		}
		i++;
	}
	return (m1);
}

t_matrix3_ptr	matrix3_transposition(t_matrix3 m1)
{
	int		i;
	int		j;
	double	buff;

	i = 0;
	while (i < 3)
	{
		j = i;
		while (j < 3)
		{
			buff = m1[i][j];
			m1[i][j] = m1[j][i];
			m1[j][i] = buff;
			j++;
		}
		i++;
	}
	return (m1);
}

t_matrix2_ptr	matrix2_transposition(t_matrix2 m1)
{
	int		i;
	int		j;
	double	buff;

	i = 0;
	while (i < 2)
	{
		j = i;
		while (j < 2)
		{
			buff = m1[i][j];
			m1[i][j] = m1[j][i];
			m1[j][i] = buff;
			j++;
		}
		i++;
	}
	return (m1);
}
