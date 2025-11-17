/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/11/14 15:17:42 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "canvas.h"
#include <X11/X.h>
#include "parsing.h"
#include <stdlib.h>
#include "keyhook.h"

void	distroy_canvas(t_canvas c)
{
	mlx_destroy_image(c.mlx, c.canva);
	mlx_destroy_window(c.mlx, c.window);
	mlx_destroy_display(c.mlx);
	free(c.mlx);
}

int	main(int ac, char **av)
{
	t_world		w;
	t_canvas	c;
	t_camera	cam;

	if (ac != 2)
		return (0);
	if (world(&w))
		return (1);
	if (parsing(av[1], &w, &cam))
	{
		free(w.obj);
		free(w.light);
		return (1);
	}
	if (init_canva(&c))
	{
		free(w.obj);
		free(w.light);
		distroy_canvas(c);
		return (1);
	}
	if (render(cam, w, c))
	{
		free(w.obj);
		free(w.light);
		distroy_canvas(c);
		return (1);
	}
	if (!mlx_put_image_to_window(c.mlx, c.window, c.canva, 0, 0))
		return (1);
	free(w.obj);
	free(w.light);
	mlx_hook(c.window, KeyPress, KeyPressMask, &actions_hook, &c);
	mlx_hook(c.window, DestroyNotify, NoEventMask, &hook_close, c.mlx);
	mlx_loop(c.mlx);
	distroy_canvas(c);
	return (0);
}
