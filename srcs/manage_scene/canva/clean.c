/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:20:48 by dernst            #+#    #+#             */
/*   Updated: 2025/11/17 16:28:39 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "stdlib.h"
#include "canvas.h"
#include "world.h"

void	distroy_canvas(t_canvas c)
{
	mlx_destroy_image(c.mlx, c.canva);
	mlx_destroy_window(c.mlx, c.window);
	mlx_destroy_display(c.mlx);
	free(c.mlx);
}

void	distroy_world(t_world w)
{
	close(w.fd);
	free(w.obj);
	free(w.light);
}

void	distroy_all(t_world w, t_canvas c)
{
	distroy_world(w);
	distroy_canvas(c);
}
