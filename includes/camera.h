/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:09:03 by njooris           #+#    #+#             */
/*   Updated: 2025/10/13 15:35:21 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "tuple.h"
#include "intersection.h"
#include "matrix.h"
#include "canvas.h"
#include "world.h"

#ifndef CAMERA_H
#define CAMERA_H

typedef struct s_camera
{
	t_matrix4	transform;
	t_matrix4	inverse_transform;
	double		vsize;
	double		hsize;
	double		half_width;
	double		half_height;
	double		fov;
	double		pixel_size;
} t_camera;

t_matrix4_ptr	view_transform(t_tuple from, t_tuple to, t_tuple up, t_matrix4 r);
t_camera		camera(double hsize, double vsize, double fov);
t_ray			ray_for_pixel(t_camera c, uint32_t px, uint32_t py);
t_canvas		render(t_camera c, t_world w, t_canvas img);
void			create_scene(t_canvas canvas);

#endif