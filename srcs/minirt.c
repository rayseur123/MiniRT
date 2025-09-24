/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 13:46:10 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "scene.h"
#include "libft.h"
#include "test.h"
#include "units.h"
#include <mlx.h>

int	init_canva(t_canvas *canvas) {

	void *mlx;
	void *mlx_win;

	mlx = mlx_init();

	canvas->height = HEIGHT_CANVA;
	canvas->width = WIDTH_CANVA;
	canvas->mlx = mlx;
	mlx_win = mlx_new_window(mlx, canvas->width, canvas->height,"¨MiniRT");
	canvas->window = mlx_win;
	canvas->canva = mlx_new_image(canvas->mlx, canvas->width, canvas->height);
	return (0);
}

int	rgb_to_int(t_rgb rgb)
{
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

int put_pixel(t_canvas *canvas, int x, int y, t_rgb color)
{
	int size_of_pixel;
	int size_of_line;
	int endian;

	canvas->addr = mlx_get_data_addr(canvas->canva, &size_of_pixel, &size_of_line, &endian);
	*(int *)(canvas->addr + ((size_of_pixel >> 3) * x) + (y * size_of_line)) = rgb_to_int(color);
}

int	main(void)
{
	t_canvas canvas;

	init_canva(&canvas);

	mlx_loop(canvas.mlx);
	return (0);
}
