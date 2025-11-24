/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:29:08 by dernst            #+#    #+#             */
/*   Updated: 2025/11/24 17:29:47 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# define NB_BOUNCE 2
# define NB_RAY 126

# include "light.h"
# include "intersection.h"

typedef struct s_world
{
	uint32_t	nb_obj;
	uint32_t	nb_light;
	t_obj		*obj;
	t_light		*light;
	t_rgb		ambient;
	uint32_t	seed;
}	t_world;

uint8_t		world(t_world *world);
void		intersect_world(t_world w, t_ray r, t_linter *linter);
t_comp		prepare_computations(t_inter *inter, t_ray ray);
t_rgb		shade_hit(t_world world, t_comp comps, t_linter linter);
t_rgb		color_at(t_world *w, t_ray r, uint32_t nb_bounce, t_linter linter);

#endif
