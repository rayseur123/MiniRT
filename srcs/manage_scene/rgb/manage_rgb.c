/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:14:09 by njooris           #+#    #+#             */
/*   Updated: 2025/10/13 12:51:39 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "world.h"
#include "mlx.h"
#include "mlx_int.h"
#include <X11/X.h>

t_rgb	color_at(t_world w, t_ray r)
{
	t_inters	inters;
	t_inter		*h;

	intersect_world(w, r, &inters);
	h = hit(&inters);
	if (!h)
		return (set_rgb(0, 0, 0));
	prepare_computations(h, r);
	return (shade_hit(w, *h));
}

int	equals_rgb(t_rgb r1, t_rgb r2)
{
	if (double_is_equal(r1.r, r2.r) && double_is_equal(r1.g, r2.g)
		&& double_is_equal(r1.b, r2.b))
		return (1);
	return (0);
}
