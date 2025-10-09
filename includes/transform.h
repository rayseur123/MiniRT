/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:41:28 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 08:44:37 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by dernst on 10/9/25.
//

#ifndef MINIRT_TRANSFORM_H
#define MINIRT_TRANSFORM_H

#include "matrix.h"
#include "object.h"

t_matrix4_ptr 	translation(double x, double y, double z, t_matrix4 m1);
t_matrix4_ptr	scaling(double x, double y, double z, t_matrix4 m);
t_matrix4_ptr	rotation_x(double radian, t_matrix4 m);
t_matrix4_ptr	rotation_y(double radian, t_matrix4 m);
t_matrix4_ptr	rotation_z(double radian, t_matrix4 m);
void			set_transform(t_obj *s, t_matrix4 m);

#endif //MINIRT_TRANSFORM_H