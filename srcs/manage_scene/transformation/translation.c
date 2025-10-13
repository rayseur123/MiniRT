/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:22:28 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 11:50:28 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix4_ptr	translation(double x, double y, double z, t_matrix4 m1)
{
	set_identity_matrix(m1);
	m1[0][3] = x;
	m1[1][3] = y;
	m1[2][3] = z;
	return (m1);
}
