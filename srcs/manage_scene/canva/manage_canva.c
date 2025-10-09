/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_canva.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:42:35 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 10:31:39 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "mlx_int.h"
#include "canvas.h"
#include <X11/X.h>

int	init_canva(t_canvas *canva)
{
	canva->width = WIDTH_CANVA;
	canva->height = HEIGHT_CANVA;
	canva->mlx = mlx_init();
	if (!canva->mlx)
		return (1);
	canva->window = mlx_new_window(canva->mlx, canva->width,
			canva->height, "MINI_RT");
	if (!canva->window)
	{
		mlx_destroy_display(canva->mlx);
		return (1);
	}
	canva->canva = mlx_new_image(canva->mlx, canva->width, canva->height);
	if (!canva->canva)
	{
		mlx_destroy_window(canva->mlx, canva->window);
		mlx_destroy_display(canva->mlx);
		return (1);
	}
	return (0);
}

int32_t	fcolor_to_uint(t_rgb col)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	if (col.r > 1)
		col.r = 1;
	if (col.g > 1)
		col.g = 1;
	if (col.b > 1)
		col.b = 1;
	if (col.r < 0)
		col.r = 0;
	if (col.g < 0)
		col.g = 0;
	if (col.b < 0)
		col.b = 0;
	r = (uint32_t)(col.r * 255);
	g = (uint32_t)(col.g * 255);
	b = (uint32_t)(col.b * 255);
	return ((r << 16) | (g << 8) | b);
}

void	put_px_in_canva(t_canvas canva, int x, int y, t_rgb rgb)
{
	int		bppx;
	int		size_line;
	int		endian;
	char	*img_data;

	img_data = mlx_get_data_addr(canva.canva, &bppx, &size_line, &endian);
	*(uint32_t *)(img_data + ((bppx >> 3) * x)
		+ (size_line * y)) = fcolor_to_uint(rgb);
}
