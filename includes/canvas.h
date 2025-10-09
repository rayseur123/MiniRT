/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:31:41 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 12:17:51 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CANVAS_H
#define MINIRT_CANVAS_H

#include <stdint.h>
#include "color.h"

#define WIDTH_CANVA 500
#define HEIGHT_CANVA 500
#define WALL_SIZE 10.00

typedef struct s_canvas
{
	uint32_t width;
	uint32_t height;
	void *mlx;
	void *window;
	void *canva;
} t_canvas;




int		init_canva(t_canvas *canva);
void	put_px_in_canva(t_canvas canva, int x, int y, t_rgb rgb);

#endif