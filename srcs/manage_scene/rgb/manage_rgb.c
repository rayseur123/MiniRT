/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:14:09 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 09:14:28 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "mlx.h"
#include "mlx_int.h"
#include <X11/X.h>

t_rgb	set_rgb(int8_t r, int8_t g, int8_t b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb	rgb_addition(t_rgb r1, t_rgb r2)
{
	t_rgb	r3;

	r3.r = r1.r + r2.r;
	r3.b = r1.b + r2.b;
	r3.g = r1.g + r2.g;
	return (r3);
}

t_rgb	rgb_subtraction(t_rgb r1, t_rgb r2)
{
	t_rgb	r3;

	r3.r = r1.r - r2.r;
	r3.b = r1.b - r2.b;
	r3.g = r1.g - r2.g;
	return (r3);
}

t_rgb	rgb_multiplication_scalar(t_rgb r1, int scale)
{
	t_rgb	r3;

	r3.r = r1.r * scale;
	r3.b = r1.b * scale;
	r3.g = r1.g * scale;
	return (r3);
}

t_rgb	rgb_multiplication(t_rgb r1, t_rgb r2)
{
	t_rgb	r3;

	r3.r = r1.r * r2.r;
	r3.b = r1.b * r2.b;
	r3.g = r1.g * r2.g;
	return (r3);
}
