/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:41:41 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 10:30:28 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "color.h"
#include "light.h"


int	test_create_light(void)
{
	t_rgb	intensity;
	t_tuple	pos;
	t_light	light;

	intensity = set_rgb(1, 1, 1);
	pos = set_point(0,0,0);
	light = point_light(pos, intensity);
	if (check_equal_tuples(light.position,pos) && light.intensity.r == intensity.r && light.intensity.g == intensity.g && light.intensity.b == intensity.b)
		return (0);
	return (1);
}

int test_default_material(void)
{
	t_material m;

	m = material();
	if (m.ambient == 0.1 && m.diffuse == 0.9 && m.spec == 0.9 && m.shininess == 200)
		return (0);
	return (1);
}

int	test_light_btw_light_surface(void)
{
	t_material m;
	t_tuple	position;
	t_tuple	eyev;
	t_tuple normalv;
	t_light	light;
	t_rgb result;

	m = material();
	position = set_point(0,0,0);
	eyev = set_vector(0,0,-1);
	normalv = set_vector(0,0,-1);
	light = point_light(set_point(0,0, -10), set_rgb(1, 1, 1));
	result = lighting(m, light, eyev, position, normalv);
	if (result.r == 1.9 && result.g == 1.9 && result.b == 1.9)
		return (0);
	return (1);
}

int	test_light_btw_light_45(void)
{
	t_material m;
	t_tuple	position;
	t_tuple	eyev;
	t_tuple normalv;
	t_light	light;
	t_rgb result;

	m = material();
	position = set_point(0,0,0);
	eyev = set_vector(0,sqrt(2) / 2,-sqrt(2) / 2);
	normalv = set_vector(0,0,-1);
	light = point_light(set_point(0,0,-10), set_rgb(1,1,1));
	result = lighting(m, light, eyev, position, normalv);
	if (result.r == 1.0 && result.g == 1.0 && result.b == 1.0)
		return (0);
	return (1);
}

int	test_light_btw_light_opposite_45(void)
{
	t_material m;
	t_tuple	position;
	t_tuple	eyev;
	t_tuple normalv;
	t_light	light;
	t_rgb result;

	m = material();
	position = set_point(0,0,0);
	eyev = set_vector(0,0,-1);
	normalv = set_vector(0,0,-1);
	light = point_light(set_point(0,10,-10), set_rgb(1,1,1));
	result = lighting(m, light, eyev, position, normalv);
	if (double_is_equal(result.r, 0.7364) && double_is_equal(result.g, 0.7364) && result.b, 0.7364)
		return (0);
	return (1);
}

int	test_light_btw_light_reflection(void)
{
	t_material m;
	t_tuple	position;
	t_tuple	eyev;
	t_tuple normalv;
	t_light	light;
	t_rgb result;

	m = material();
	position = set_point(0,0,0);
	eyev = set_vector(0,-sqrt(2) / 2,-sqrt(2) / 2);
	normalv = set_vector(0,0,-1);
	light = point_light(set_point(0,10,-10), set_rgb(1,1,1));
	result = lighting(m, light, eyev, position, normalv);
	if (double_is_equal(result.r, 1.6364) && double_is_equal(result.g, 1.6364) && result.b, 1.6364)
		return (0);
	return (1);
}

int	test_light_behind_surface(void)
{
	t_material m;
	t_tuple	position;
	t_tuple	eyev;
	t_tuple normalv;
	t_light	light;
	t_rgb result;

	m = material();
	position = set_point(0,0,0);
	eyev = set_vector(0,0,-1);
	normalv = set_vector(0,0,-1);
	light = point_light(set_point(0,0,10), set_rgb(1,1,1));
	result = lighting(m, light, eyev, position, normalv);
	if (result.r == 0.1 && result.g == 0.1 && result.b == 0.1)
		return (0);
	return (1);
}