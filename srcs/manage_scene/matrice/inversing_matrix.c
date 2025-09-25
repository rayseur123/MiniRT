/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversing_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 05:08:27 by njooris           #+#    #+#             */
/*   Updated: 2025/09/25 13:09:40 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

int	matrix4_is_reversible(t_matrix4 m)
{
	return (!double_is_equal(determining_matrix4(m), 0));
}

void	matrix4_cpy(t_matrix4 src, t_matrix4 dest)
{
	int	i = 0;
	int	j;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

t_matrix4_ptr	matrix4_reverse(t_matrix4 m1, t_matrix4 m2)
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
