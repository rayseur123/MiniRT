/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:42:14 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 08:45:56 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by dernst on 10/9/25.
//

#ifndef MINIRT_SPHERE_H
#define MINIRT_SPHERE_H

#include <stdint.h>
#include "canvas.h"
#include "object.h"
#include "intersection.h"

uint32_t 		intersect_sphere(t_obj *s, t_ray r, t_inters *inters);
t_obj			sphere(void);
void			draw_sphere(t_canvas canvas);

#endif //MINIRT_SPHERE_H