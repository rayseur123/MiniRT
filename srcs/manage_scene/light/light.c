/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:06:49 by njooris           #+#    #+#             */
/*   Updated: 2025/11/24 17:35:25 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "intersection.h"

t_light	point_light(t_tuple	position, t_rgb inte)
{
	t_light	l;

	l.intensity = inte;
	l.position = position;
	return (l);
}

t_rgb	asb_phong(t_rgb c, t_lighting l, double light, t_rgb spec)
{
	t_rgb	diffuse;

	diffuse = cal_diffuse(c, light, l.mat);
	return (rgb_addition(diffuse, spec));
}

t_rgb	lighting(t_lighting l,
				t_tuple point, t_tuple normalv, bool is_shadowed)
{
	t_rgb	ef_color;
	t_tuple	lightv;
	double	light_dot_normal;

	lightv = tuple_normalization(tuple_subtraction(l.light.position, point));
	light_dot_normal = dot_product(lightv, normalv);
	ef_color = rgb_multiplication(l.mat.color, l.light.intensity);
	if (light_dot_normal < 0 || is_shadowed)
		return (set_rgb(0, 0, 0));
	return (asb_phong(ef_color, l, light_dot_normal,
			set_rgb(0, 0, 0)));
}
