/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/10/22 15:12:43 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "test.h"
#include "units.h"
#include "../includes/test.h"
#include "canvas.h"
#include "sphere.h"
#include "mlx.h"
#include "mlx_int.h"
#include <X11/X.h>
#include "camera.h"
#include "parsing.h"
#include "world.h"
#include <stdlib.h>
#include <time.h>

void	escape(int key_code, t_canvas *c)
{
	if (key_code == 65307)
		mlx_loop_end(c->mlx);
}

int	actions_hook(int key_code, t_canvas *c)
{
	escape(key_code, c);
	return (0);
}

int	hook_close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

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
	if (!render(cam, w, c))
		mlx_put_image_to_window(c.mlx, c.window, c.canva, 0, 0);
	free(w.obj);
	free(w.light);
	mlx_hook(c.window, KeyPress, KeyPressMask, &actions_hook, &c);
	mlx_hook(c.window, DestroyNotify, NoEventMask, &hook_close, c.mlx);
	//mlx_loop(c.mlx);
	mlx_destroy_image(c.mlx, c.canva);
	mlx_destroy_window(c.mlx, c.window);
	mlx_destroy_display(c.mlx);
	free(c.mlx);
	return (0);
}
