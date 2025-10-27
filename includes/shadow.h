/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:16:57 by dernst            #+#    #+#             */
/*   Updated: 2025/10/27 11:13:31 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
#define SHADOW_H

#include "tuple.h"
#include "world.h"

bool is_shadowed(t_world world, t_tuple point, t_light light);

#endif