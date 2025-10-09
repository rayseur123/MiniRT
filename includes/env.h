/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:34:06 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 10:44:09 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENV_H
#define ENV_H

#include "tuple.h"

typedef struct s_projectile
{
	t_tuple position;
	t_tuple velocity;
} t_projectile;

typedef struct s_environment
{
	t_tuple gravity;
	t_tuple wind;
} t_environment;

t_projectile	tick(t_environment env, t_projectile proj);

#endif  //PROJECTILE_H