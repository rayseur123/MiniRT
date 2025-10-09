/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:28:59 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 08:46:38 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by dernst on 10/9/25.
//

#ifndef MINIRT_LIGHT_H
#define MINIRT_LIGHT_H

#include "color.h"
#include "tuple.h"

typedef struct s_light
{
	t_rgb	intensity;
	t_tuple	position;
}	t_light;

t_material	material(void);
t_light		point_light(t_tuple	position, t_rgb inte);
t_rgb		lighting(t_material mat, t_light l, t_tuple eyev, t_tuple point, t_tuple normalv);

#endif //MINIRT_LIGHT_H