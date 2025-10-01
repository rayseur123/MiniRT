/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/10/01 11:32:59 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "scene.h"
#include "libft.h"
#include "test.h"
#include "units.h"

int	main(void)
{
	// t_function	*test;

	// test = NULL;
	// lib_unit();
	// launch_lib_test(&test);

	t_canvas canvas;
	t_rgb	red;

	red.r = 127;
	red.g = 0;
	red.b = 0;

	// lib_unit();
	// launch_lib_test(&test);
	init_canva(&canvas);
	draw_sphere(canvas);
	mlx_put_image_to_window(canvas.mlx, canvas.window, canvas.canva, 0, 0);
	mlx_loop(canvas.mlx);
	return (0);
}
