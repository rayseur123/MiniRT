/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:23:02 by dernst            #+#    #+#             */
/*   Updated: 2025/10/28 10:43:20 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <light.h>
#include <transform.h>
#include "intersection.h"
#include "sphere.h"
#include "world.h"
#include <stdlib.h>
#include <math.h>
#include "camera.h"

void	create_scene(t_canvas canvas)
{
t_obj	floor;
	t_obj	left_wall;
	t_obj	right_wall;
	t_obj	right;
	t_obj	left;
	t_obj	middle;
	t_matrix4 trans1;
	t_matrix4 rotatex1;
	t_matrix4 rotatey1;
	t_matrix4 scaling1;
	t_matrix4 mult;
	t_world		world;
	t_camera	c;
	const double pi = 2 * acos(0.0);

	// Floor
	floor = shape(PLANE);
	set_identity_matrix(floor.transform);
	matrix4_inverse(floor.transform, floor.inverse_transform);
	floor.material = material();

	// Left wall
	left_wall = shape(PLANE);
	translation(0, 0, 5, trans1);
	rotation_y(-pi / 4, rotatey1);
	rotation_x(pi / 2, rotatex1);

	matrix4_multiplication(trans1, rotatey1, left_wall.transform);
	matrix4_multiplication(left_wall.transform, rotatex1, mult);
	matrix4_inverse(mult, left_wall.inverse_transform);
	left_wall.material = floor.material;

	// Right wall
	right_wall = shape(PLANE);
	translation(0, 0, 5, trans1);
	rotation_y(pi / 4, rotatey1);
	rotation_x(pi / 2, rotatex1);

	matrix4_multiplication(trans1, rotatey1, right_wall.transform);
	matrix4_multiplication(right_wall.transform, rotatex1, mult);
	matrix4_inverse(mult, right_wall.inverse_transform);
	right_wall.material = floor.material;

	right_wall.material = floor.material;

	// Right sphere
	right = shape(SPHERE);
	translation(2, 3, -0.5, trans1);
	scaling(1.42, 1.42, 1.42, scaling1);
	matrix4_multiplication(trans1, scaling1, right.transform);
	matrix4_inverse(right.transform, right.inverse_transform);
	right.material = material();
	right.material.color = set_rgb(0.5, 1, 0.1);
	right.material.diffuse = 0.7;
	right.material.spec = 0.3;

	// middle sphere
	middle = shape(SPHERE);
	translation(0, 1, -2, trans1);
	scaling(1, 1, 1, scaling1);
	matrix4_multiplication(trans1, scaling1, middle.transform);
	matrix4_inverse(middle.transform, middle.inverse_transform);
	middle.material = material();
	middle.material.color = set_rgb(0.8, 0, 0.1);
	middle.material.diffuse = 0.7;
	middle.material.spec = 0.3;

	// Left sphere
	left = shape(SPHERE);
	translation(-1.5, 0.33, -0.75, trans1);
	scaling(0.33, 0.33, 0.33, scaling1);
	matrix4_multiplication(trans1, scaling1, left.transform);
	matrix4_inverse(left.transform, left.inverse_transform);
	left.material = material();
	left.material.color = set_rgb(1, 0.8, 0.1);
	left.material.diffuse = 0.7;
	left.material.spec = 0.3;

	// World setup
	world.light = malloc(1 * sizeof(t_light));
	world.obj = malloc(6 * sizeof(t_obj));
	world.nb_light = 1;
	world.nb_obj = 6;
	world.light[0] = point_light(set_point(2, 5, -10), set_rgb(1, 1, 1));

	world.obj[0] = floor;
	world.obj[1] = left_wall;
	world.obj[2] = right_wall;
	world.obj[3] = right;
	world.obj[4] = left;
	world.obj[5] = middle;

	c = camera(WIDTH_CANVA, HEIGHT_CANVA, pi/3);
	view_transform(set_point(0, 3, -20), set_point(0, 1, 0), set_vector(0, 1, 0), c.transform);
	matrix4_inverse(c.transform, c.inverse_transform);
	render(c, world, canvas);
}
