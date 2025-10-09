/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 03:58:44 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 10:46:18 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix3_cofactor(t_matrix3 m, int row, int col)
{
	double	minor_m;

	minor_m = matrix3_minor(m, row, col);
	if ((row + col) % 2)
		minor_m = -minor_m;
	return (minor_m);
}

double	matrix4_cofactor(t_matrix4 m, int row, int col)
{
	double	minor_m;

	minor_m = matrix4_minor(m, row, col);
	if ((row + col) % 2)
		minor_m = -minor_m;
	return (minor_m);
}
