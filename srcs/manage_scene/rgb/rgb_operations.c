/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:51:15 by njooris           #+#    #+#             */
/*   Updated: 2025/10/13 12:51:31 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:14:09 by njooris           #+#    #+#             */
/*   Updated: 2025/10/13 12:33:07 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "world.h"
#include "mlx.h"
#include "mlx_int.h"
#include <X11/X.h>

t_rgb	set_rgb(const double r, const double g, const double b)
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

t_rgb	rgb_multiplication_scalar(t_rgb r1, double scale)
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

