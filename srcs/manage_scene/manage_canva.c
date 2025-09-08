/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_canva.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:42:35 by njooris           #+#    #+#             */
/*   Updated: 2025/09/04 16:28:04 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "mlx.h"
#include "mlx_int.h"
#include <X11/X.h>

t_rgb	set_rgb(int8_t r, int8_t g, int8_t b)
{
	t_rgb rgb;

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
	return(r3);
}

t_rgb	rgb_subtraction(t_rgb r1, t_rgb r2)
{
	t_rgb	r3;

	r3.r = r1.r - r2.r;
	r3.b = r1.b - r2.b;
	r3.g = r1.g - r2.g;
	return(r3);
}

t_rgb	rgb_multiplication_scalar(t_rgb r1, int scale)
{
	t_rgb	r3;

	r3.r = r1.r * scale;
	r3.b = r1.b * scale;
	r3.g = r1.g * scale;
	return(r3);
}

t_rgb	rgb_multiplication(t_rgb r1, t_rgb r2)
{
	t_rgb	r3;

	r3.r = r1.r * r2.r;
	r3.b = r1.b * r2.b;
	r3.g = r1.g * r2.g;
	return(r3);
}

int	init_canva(t_canvas *canva)
{
	canva->width = WIDTH_CANVA;
	canva->height = HEIGHT_CANVA;
	canva->mlx = mlx_init();
	if (!canva->mlx)
		return (1);
	canva->window = mlx_new_window(canva->mlx, canva->width, canva->height, "MINI_RT");
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

int		rgb_to_int(t_rgb rgb)
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
