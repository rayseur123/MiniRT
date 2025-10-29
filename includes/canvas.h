/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:31:41 by dernst            #+#    #+#             */
/*   Updated: 2025/10/28 13:17:07 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CANVAS_H
#define MINIRT_CANVAS_H

#include <stdint.h>
#include "color.h"

#define WIDTH_CANVA 1000
#define HEIGHT_CANVA 800

typedef struct s_canvas
{
	int width;
	int height;
	void *mlx;
	void *window;
	void *canva;
} t_canvas;

int			init_canva(t_canvas *canva);
void		put_px_in_canva(t_canvas canva, int x, int y, t_rgb rgb);
uint32_t	fcolor_to_uint(t_rgb col);
uint32_t	pixel_at(t_canvas canva, int x, int y);

#endif
