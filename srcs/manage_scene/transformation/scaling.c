/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:06:07 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 10:47:01 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix4_ptr	scaling(double x, double y, double z, t_matrix4 m)
{
	set_identity_matrix(m);
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
	return (m);
}
