/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/10/08 16:36:24 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "scene.h"
#include "libft.h"
#include "test.h"
#include "units.h"
#include "../includes/test.h"

int	main(void)
{
	t_function	*test;
	t_canvas	canvas;
	t_rgb		red;
	
	test = NULL;
	lib_unit();
	launch_lib_test(&test);
	red.r = 127;
	red.g = 0;
	red.b = 0;
	test_world_3();
	init_canva(&canvas);
	draw_sphere(canvas);
	mlx_put_image_to_window(canvas.mlx, canvas.window, canvas.canva, 0, 0);
	mlx_loop(canvas.mlx);
	return (0);
}
