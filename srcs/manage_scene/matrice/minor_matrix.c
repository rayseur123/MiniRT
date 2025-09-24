/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:45:33 by njooris           #+#    #+#             */
/*   Updated: 2025/09/24 13:42:45 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

double	matrix3_minor(t_matrix3 m, int row, int col)
{
	t_matrix2	m2;

	matrix3_submatrix(m, m2, row, col);
	return (determining_matrix2(m2));
}

double	matrix4_minor(t_matrix4 m, int row, int col)
{
	t_matrix3	m2;

	matrix4_submatrix(m, m2, row, col);
	return (determining_matrix3(m2));
}
