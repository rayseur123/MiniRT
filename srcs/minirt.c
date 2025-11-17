/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/11/17 09:04:23 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "canvas.h"
#include <X11/X.h>
#include "parsing.h"
#include <stdlib.h>
#include "keyhook.h"
#include <unistd.h>
#include "clean.h"

void	canvas_manage(t_canvas c)
{
	mlx_hook(c.window, KeyPress, KeyPressMask, &actions_hook, &c);
	mlx_hook(c.window, DestroyNotify, NoEventMask, &hook_close, c.mlx);
	mlx_loop(c.mlx);
}

int	minirt_init(t_world *w, int ac, char **av, t_camera *cam)
{
	if (ac != 2)
		return (0);
	if (world(w))
		return (1);
	if (parsing(av[1], w, cam))
	{
		distroy_world(*w);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_world		w;
	t_canvas	c;
	t_camera	cam;

	if (minirt_init(&w, ac, av, &cam))
		return (1);
	if (init_canva(&c))
	{
		distroy_all(w, c);
		return (1);
	}
	if (render(cam, w, c))
	{
		distroy_all(w, c);
		return (1);
	}
	if (!mlx_put_image_to_window(c.mlx, c.window, c.canva, 0, 0))
	{
		distroy_all(w, c);
		return (1);
	}
	canvas_manage(c);
	distroy_all(w, c);
	return (0);
}
