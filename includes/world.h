/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:29:08 by dernst            #+#    #+#             */
/*   Updated: 2025/10/24 13:00:07 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_WORLD_H
#define MINIRT_WORLD_H

#include <stdint.h>
#include "light.h"
#include "intersection.h"

#define NB_BOUNCE 2
#define NB_RAY 1

typedef struct s_world
{
	uint32_t	nb_obj;
	uint32_t	nb_light;
	t_obj		*obj;
	t_light		*light;
	int			fd;
}	t_world;

t_world		world(void);
uint32_t	intersect_world(t_world w, t_ray r, t_inters *inters);
void		prepare_computations(t_inter *inter, t_ray ray);
t_rgb		shade_hit(t_world world, t_inter comps);
t_rgb		color_at(t_world w, t_ray r, uint32_t nb_bounce, t_inters inters);
t_world 	default_world(void);

#endif