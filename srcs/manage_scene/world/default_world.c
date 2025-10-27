/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:37:35 by njooris           #+#    #+#             */
/*   Updated: 2025/10/14 14:40:50 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "sphere.h"
#include "stdlib.h"
#include "transform.h"
#include <stdio.h>

t_world	default_world(void)
{
	t_world	w;

	w = world();
	w.light = malloc(4 * sizeof(t_light));
	w.light[0] = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));
	w.obj = malloc(4 * sizeof(t_obj));
	w.nb_obj = 2;
	w.nb_light = 1;
	w.obj[0] = shape(SPHERE);
	w.obj[1] = shape(SPHERE);
	w.obj[0].material.color = set_rgb(0.8, 1.0, 0.6);
	w.obj[0].material.diffuse = 0.7;
	w.obj[0].material.spec = 0.2;
	scaling(0.5, 0.5, 0.5, w.obj[1].transform);
	matrix4_inverse(w.obj[0].transform, w.obj[0].inverse_transform);
	matrix4_inverse(w.obj[1].transform, w.obj[1].inverse_transform);
	return (w);
}
