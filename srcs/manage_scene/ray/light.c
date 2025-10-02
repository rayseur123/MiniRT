/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:06:49 by njooris           #+#    #+#             */
/*   Updated: 2025/10/02 13:48:54 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

t_material	material(void)
{
	t_material	mat;

	mat.ambient = 0.1;
	mat.diffus = 0.9;
	mat.spec = 0.9;
	mat.shininess = 200;
	return (mat);
}

t_p_light	point_light(t_tuple	position, t_rgb inte)
{
	t_p_light	l;

	l.intensity = inte;
	l.position = position;
	return (l);
}

t_rgb	lighting(t_material mat, t_p_light l, t_tuple eyev, t_tuple point, t_tuple normalv)
{
	t_rgb	ef_color;
	t_tuple	lightv;
	t_rgb	ambient;
	double	light_dot_normal;
	double	reflect_dot_eye;
	t_rgb	spec;
	t_rgb	diffuse;
	t_tuple reflectv;
	double	factor;

	ef_color = rgb_multiplication(mat.color, l.intensity);
	lightv = tuple_normalization(tuple_subtraction(l.position, point));
	ambient = rgb_multiplication_scalar(ef_color, mat.ambient);
	light_dot_normal = dot_product(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = set_rgb(0, 0, 0);
		spec = set_rgb(0, 0, 0);
	}
	else
	{
		diffuse = rgb_multiplication_scalar(rgb_multiplication_scalar(ef_color, mat.diffus), light_dot_normal); 
		reflectv = reflect(tuple_negation(lightv), normalv);
		reflect_dot_eye = dot_product(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			spec = set_rgb(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, mat.shininess);
			spec = rgb_multiplication_scalar(rgb_multiplication_scalar(l.intensity, mat.spec), factor);
		}
	}
	return (rgb_addition(rgb_addition(ambient, diffuse), spec));
}