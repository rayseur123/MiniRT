/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:22:28 by njooris           #+#    #+#             */
/*   Updated: 2025/09/23 15:06:59 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_matrix4_ptr translation(double x, double y, double z, t_matrix4 m1)
{
	set_identity_matrix(m1);
	m1[0][3] = x;
	m1[1][3] = y;
	m1[2][3] = z;
	return (m1);
}

