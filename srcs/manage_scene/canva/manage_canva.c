/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_canva.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:42:35 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 09:14:26 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "mlx.h"
#include "mlx_int.h"
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

int	rgb_to_int(t_rgb rgb)
{
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

void	put_px_in_canva(t_canvas canva, int x, int y, t_rgb rgb)
{
	int		bppx;
	int		size_line;
	int		endian;
	char	*img_data;

	img_data = mlx_get_data_addr(canva.canva, &bppx, &size_line, &endian);
	*(int *)(img_data + ((bppx >> 3) * x) + (size_line * y)) = rgb_to_int(rgb);
}
