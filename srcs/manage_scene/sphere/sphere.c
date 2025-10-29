/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:14:57 by njooris           #+#    #+#             */
/*   Updated: 2025/10/28 13:53:16 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "color.h"
#include "light.h"
#include "canvas.h"
#include <math.h>
#include <stdlib.h>

t_material	material(void)
{
	t_material	mat;

	mat.ambient = 0.1;
	mat.diffuse = 0.9;
	mat.spec = 0.9;
	mat.shininess = 200;
	mat.color = set_rgb(1, 1, 1);
	return (mat);
}

void	set_transform(t_obj *s, t_matrix4 m)
{
	matrix4_cpy(s->transform, m);
}
