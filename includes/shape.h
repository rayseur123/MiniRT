/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:35:35 by dernst            #+#    #+#             */
/*   Updated: 2025/11/12 17:27:37 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

#include "color.h"
#include "matrix.h"
#include "intersection.h"

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

typedef struct s_obj
{
	t_obj_type	type;
	int			id;
	t_matrix4	transform;
	t_matrix4	inverse_transform;
	t_material	material;
	double		min;
	double		max;
	bool		closed;
}	t_obj;

t_obj			shape(enum e_obj_type type);

#endif