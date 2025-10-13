/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_is_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:16:54 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 10:46:07 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

uint8_t	matrix4_is_equal(t_matrix4 m1, t_matrix4 m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!double_is_equal(m1[i][j], m2[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

uint8_t	matrix3_is_equal(t_matrix3 m1, t_matrix3 m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (!double_is_equal(m1[i][j], m2[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

uint8_t	matrix2_is_equal(t_matrix2 m1, t_matrix2 m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			if (!double_is_equal(m1[i][j], m2[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
