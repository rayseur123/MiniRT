/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:42:16 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 09:19:21 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "scene.h"
#include "libft.h"
#include "test.h"

int	main(void)
{
	t_canvas		canva;
	t_rgb			rgb;
	t_projectile	p;
	t_environment	e;

	init_canva(&canva);
	rgb = set_rgb((u_int8_t)128, (u_int8_t)128, (u_int8_t)128);
	p.position = set_point(0, 1, 0);
	p.velocity = tuple_multiplication (tuple_normalization(
				set_vector(1, 1.8, 0)), 11.25);
	e.gravity = set_vector(0, -0.1, 0);
	e.wind = set_vector(-0.01, 0, 0);
	while (p.position.y >= 0)
	{
		put_px_in_canva(canva, p.position.x, p.position.y, rgb);
		p = tick(e, p);
	}
	mlx_put_image_to_window(canva.mlx, canva.window, canva.canva, 0, 0);
	mlx_loop(canva.mlx);
	return (0);
}
