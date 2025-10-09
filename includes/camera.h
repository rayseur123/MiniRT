/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:09:03 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 12:46:15 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "tuple.h"
#include "matrix.h"

#ifndef CAMERA_H
#define CAMERA_H

typedef struct s_camera
{
	t_matrix4	transform;
	uint32_t	vsize;
	uint32_t	hsize;
	double		half_width;
	double		half_height;
	double		fov;
	double		pixel_size;
} t_camera;

t_matrix4_ptr	view_transform(t_tuple from, t_tuple to, t_tuple up, t_matrix4 r);
t_camera		camera(uint32_t hsize, uint32_t vsize, double fov);

#endif