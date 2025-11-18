/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:17:08 by njooris           #+#    #+#             */
/*   Updated: 2025/11/18 10:08:47 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "camera.h"
#include "minirt_error.h"

int	render(t_camera c, t_world w, t_canvas img)
{
	int			x;
	int			y;
	t_rgb		color;
	t_linter	linter;

	x = 0;
	linter.inters = malloc((2 * w.nb_obj) * sizeof(t_inter));
	if (!linter.inters)
	{
		print_error(MALLOC_ERROR);
		return (1);
	}
	while (x < c.hsize)
	{
		y = 0;
		while (y < c.vsize)
		{
			color = color_at(w, ray_for_pixel(c, x, y), 1, linter);
			put_px_in_canva(img, x, y, color);
			y++;
		}
		x++;
	}
	free(linter.inters);
	return (0);
}
