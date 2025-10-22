/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/10/22 10:15:23 by njooris          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_world		w;
	t_canvas	c;
	t_camera	cam;

	(void)ac;
	w = world();
	if (parsing(av[1], &w, &cam))
		return (-1);
	init_canva(&c);
	// create_scene(c);
	render(cam, w, c);
	printf("end\n");
	mlx_put_image_to_window(c.mlx, c.window, c.canva, 0, 0);
	free(w.obj);
	free(w.light);
	mlx_loop(c.mlx);
	mlx_destroy_image(c.mlx, c.canva);
	mlx_destroy_window(c.mlx, c.window);
	mlx_destroy_display(c.mlx);
	return (0);
}
