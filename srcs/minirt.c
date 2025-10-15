/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/10/14 16:34:40 by njooris          ###   ########.fr       */
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

int	test_init(t_canvas canva, t_world world)
{
	t_camera	c;
	const double pi = 2 * acos(0.0);

	// World setup
	world.light = malloc(1 * sizeof(t_light));
	world.nb_light = 1;
	world.light[0] = point_light(set_point(-10, 10, -10), set_rgb(1, 1, 1));


	c = camera(WIDTH_CANVA, HEIGHT_CANVA, pi/3);
	view_transform(set_point(0, 1.5, -5), set_point(0, 1, 0), set_vector(0, 1, 0), c.transform);
	matrix4_inverse(c.transform, c.inverse_transform);
	render(c, world, canva);
	return (0);
}

int	main(int ac, char **av)
{
	t_world	world;
	t_canvas c;

	if (ac > 2)
		return (1);
	if (ac < 2)
		world = default_world();
	else
	{
		if (parsing(av[1], &world))
			return (-1);
	}
	init_canva(&c);
	test_init(c, world);
	mlx_put_image_to_window(c.mlx, c.window, c.canva, 0, 0);
	mlx_loop(c.mlx);
	return (0);
}
