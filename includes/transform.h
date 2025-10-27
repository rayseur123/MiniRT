/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:41:28 by dernst            #+#    #+#             */
/*   Updated: 2025/10/24 15:15:13 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by dernst on 10/9/25.
//

#ifndef MINIRT_TRANSFORM_H
#define MINIRT_TRANSFORM_H

#include "matrix.h"
#include "intersection.h"

t_matrix4_ptr 	translation(double x, double y, double z, t_matrix4 m1);
t_matrix4_ptr	scaling(double x, double y, double z, t_matrix4 m);
t_matrix4_ptr	rotation_x(double radian, t_matrix4 m);
t_matrix4_ptr	rotation_y(double radian, t_matrix4 m);
t_matrix4_ptr	rotation_z(double radian, t_matrix4 m);
void			set_transform(t_obj *s, t_matrix4 m);

#endif //MINIRT_TRANSFORM_H