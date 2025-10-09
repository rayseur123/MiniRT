/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:29:08 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 10:28:50 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_WORLD_H
#define MINIRT_WORLD_H

#include <stdint.h>
#include "light.h"
#include "object.h"
#include "intersection.h"

typedef struct s_world
{
	uint32_t	nb_obj;
	uint32_t	nb_light;
	t_obj		*obj;
	t_light		*light;
}	t_world;

t_world	world(void);
uint32_t	intersect_world(t_world w, t_ray r, t_inters *inters);
void		prepare_computations(t_inter *inter, t_ray ray);
t_rgb		shade_hit(t_world world, t_inter comps);
t_rgb		color_at(t_world w, t_ray r);
#endif //MINIRT_WORLD_H