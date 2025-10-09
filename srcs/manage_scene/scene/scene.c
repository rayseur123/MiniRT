/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:23:02 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 16:32:35 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <light.h>
#include <transform.h>
#include "object.h"
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
	t_obj	middle;
	t_obj	right;
	t_obj	left;
	t_matrix4 trans1;
	t_matrix4 rotatex1;
	t_matrix4 rotatey1;
	t_matrix4 scaling1;
	t_matrix4 mult;
	t_world		world;
	t_camera	c;
	const double pi = 2 * acos(0.0);

	floor = sphere();
	scaling(10, 0.01, 10, floor.transform);
	floor.material = material();
	floor.material.color = set_rgb(1,0.9,0.9);
	floor.material.spec = 0;

	left_wall = sphere();
	translation(0,0,5, trans1);
	rotation_y(-pi / 4,rotatey1);
	rotation_x(pi / 2, rotatex1);
	scaling(10,0.01,10, scaling1);
	matrix4_multiplication(trans1, rotatey1, mult);
	matrix4_multiplication(mult, rotatex1, mult);
	matrix4_multiplication(mult, scaling1, mult);
	matrix4_multiplication(mult, left_wall.transform, left_wall.transform);
	left_wall.material = floor.material;

	right_wall = sphere();
	translation(0,0,5, trans1);
	rotation_y(pi / 4,rotatey1);
	rotation_x(pi / 2, rotatex1);
	scaling(10,0.01,10, scaling1);
	matrix4_multiplication(trans1, rotatey1, mult);
	matrix4_multiplication(mult, rotatex1, mult);
	matrix4_multiplication(mult, scaling1, mult);
	matrix4_multiplication(mult, left_wall.transform, right_wall.transform);
	right_wall.material = floor.material;

	middle = sphere();
	translation(-0.5,1,0.5, middle.transform);
	middle.material = material();
	middle.material.color = set_rgb(0.1,1,0.5);
	middle.material.diffuse = 0.7;
	middle.material.spec = 0.3;

	right = sphere();
	translation(1.5,0.5,-0.5, trans1);
	scaling(0.5,0.5,0.5, scaling1);
	matrix4_multiplication(trans1, scaling1, mult);
	matrix4_multiplication(mult, left_wall.transform, right_wall.transform);
	right.material = material();
	right.material.color = set_rgb(0.5,1,0.1);
	right.material.diffuse = 0.7;
	right.material.spec = 0.3;

	left = sphere();
	translation(-1.5,0.33,-0.75, trans1);
	scaling(0.33,0.33,0.33, scaling1);
	matrix4_multiplication(trans1, scaling1, mult);
	matrix4_multiplication(mult, left_wall.transform, right_wall.transform);
	left.material = material();
	left.material.color = set_rgb(1,0.8,0.1);
	left.material.diffuse = 0.7;
	left.material.spec = 0.3;
	world.light = malloc(1 * sizeof(t_light));
	world.obj = malloc(6 * sizeof(t_obj));
	world.nb_light = 1;
	world.nb_obj = 6;
	world.light[0] = point_light(set_point(-10,10,-10), set_rgb(1,1,1));

	c = camera(100, 50,pi/10);
	world.obj[0] = floor;
	world.obj[1] = left_wall;
	world.obj[2] = right_wall;
	world.obj[3] = middle;
	world.obj[4] = right;
	world.obj[5] = left;

	view_transform(set_point(0,1.5,-5), set_point(0,1,0), set_vector(0,1,0), c.transform);
	render(c, world, canvas);
}

