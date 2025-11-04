/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/11/04 10:48:32 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "canvas.h"
#include <X11/X.h>
#include "parsing.h"
#include <stdlib.h>
#include "keyhook.h"

int	main(int ac, char **av)
{
	t_world		w;
	t_canvas	c;
	t_camera	cam;

	if (ac != 2)
		return (0);
	w = world();
	if (parsing(av[1], &w, &cam))
		return (1);
	init_canva(&c);
	render(cam, w, c);
	mlx_put_image_to_window(c.mlx, c.window, c.canva, 0, 0);
	free(w.obj);
	free(w.light);
	mlx_hook(c.window, KeyPress, KeyPressMask, &actions_hook, &c);
	mlx_hook(c.window, DestroyNotify, NoEventMask, &hook_close, c.mlx);
	mlx_loop(c.mlx);
	mlx_destroy_image(c.mlx, c.canva);
	mlx_destroy_window(c.mlx, c.window);
	mlx_destroy_display(c.mlx);
	free(c.mlx);
	return (0);
}
