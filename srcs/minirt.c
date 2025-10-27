/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/10/27 09:02:58 by dernst           ###   ########.fr       */
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

int	main(void)
{
	t_function	*test;
	t_canvas	canvas;

	test = NULL;
	lib_unit();
	launch_lib_test(&test);
	init_canva(&canvas);
	create_scene(canvas);
	mlx_put_image_to_window(canvas.mlx, canvas.window, canvas.canva, 0, 0);
	mlx_loop(canvas.mlx);
	return (0);
}
