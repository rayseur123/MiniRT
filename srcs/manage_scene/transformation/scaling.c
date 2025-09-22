/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:06:07 by njooris           #+#    #+#             */
/*   Updated: 2025/09/22 16:40:34 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_matrix4 *scaling(double x, double y, double z, t_matrix4 m1)
{
	set_identity_matrix(m1);
	m1[3][3] = 1;
	return (m1);
}
