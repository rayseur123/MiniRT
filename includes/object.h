/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:35:35 by dernst            #+#    #+#             */
/*   Updated: 2025/10/28 14:48:15 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJECT_H
#define MINIRT_OBJECT_H

#include "matrix.h"
#include "color.h"
#include "intersection.h"

void	intersect_cylinder(t_obj *o, const t_ray r, t_inters *xs);
void	intersect_plane(t_obj *o, const t_ray r, t_inters *xs);
uint32_t	intersect_sphere(t_obj *s, const t_ray r, t_inters *inters);

#endif //MINIRT_OBJECT_H
