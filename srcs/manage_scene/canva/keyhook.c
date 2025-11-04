/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:37:14 by dernst            #+#    #+#             */
/*   Updated: 2025/10/31 10:58:56 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "mlx.h"
#include "mlx_int.h"
#include <X11/X.h>

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
