/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:04:55 by dernst            #+#    #+#             */
/*   Updated: 2025/11/18 10:33:49 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_rgb	cal_ambient(t_rgb *ef_color, t_light l, t_material mat)
{
	*ef_color = rgb_multiplication(mat.color, l.intensity);
	return (rgb_multiplication_scalar(*ef_color, mat.ambient));
}

t_rgb	cal_diffuse(const t_rgb ef_color, const double light, t_material mat)
{
	return (rgb_multiplication_scalar(
			rgb_multiplication_scalar(ef_color, mat.diffuse), light));
}

t_rgb	cal_spec(t_material mat, double reflect_dot_eye, t_light l)
{
	double	factor;

	factor = pow(reflect_dot_eye, mat.shininess);
	if (reflect_dot_eye <= 0)
	{
		return (set_rgb(0, 0, 0));
	}
	return (rgb_multiplication_scalar(
			rgb_multiplication_scalar(l.intensity, mat.spec), factor));
}
