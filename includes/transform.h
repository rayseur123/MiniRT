/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:41:28 by dernst            #+#    #+#             */
/*   Updated: 2025/11/19 16:16:36 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

t_matrix4_ptr	translation(double x, double y, double z, t_matrix4 m1);
t_matrix4_ptr	scaling(double x, double y, double z, t_matrix4 m);
t_matrix4_ptr	rotation_x(double radian, t_matrix4 m);
t_matrix4_ptr	rotation_y(double radian, t_matrix4 m);
t_matrix4_ptr	rotation_z(double radian, t_matrix4 m);

#endif
