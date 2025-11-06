/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:42:14 by dernst            #+#    #+#             */
/*   Updated: 2025/11/05 11:46:06 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_SPHERE_H
#define MINIRT_SPHERE_H

#include <stdint.h>
#include "canvas.h"
#include "intersection.h"

uint32_t 		intersect_sphere(t_obj *s, t_ray r, t_linter *inters);

#endif

