/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:52:40 by dernst            #+#    #+#             */
/*   Updated: 2025/11/18 10:34:36 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

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

t_obj	shape(enum e_obj_type const type)
{
	static int32_t	id;
	t_obj			obj;

	obj.id = id++;
	obj.type = type;
	obj.material = material();
	set_identity_matrix(obj.transform);
	set_identity_matrix(obj.inverse_transform);
	if (type == CYLINDER)
	{
		obj.max = 100;
		obj.min = -100;
		obj.closed = true;
	}
	return (obj);
}
