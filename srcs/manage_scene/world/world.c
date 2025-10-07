/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:37:35 by njooris           #+#    #+#             */
/*   Updated: 2025/10/07 15:55:48 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_world	world(void)
{
	t_world	w;

	w.nb_light = 0;
	w.nb_obj = 0;
	w.light = NULL;
	w.obj = 0;
	return (w);
}

void	prepare_computation(t_inter *inter, t_ray ray)
{
	inter->point = position(ray, inter->range);
}