/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:25:19 by njooris           #+#    #+#             */
/*   Updated: 2025/10/29 16:30:17 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "sphere.h"
#include "libft.h"
#include "transform.h"
#include <math.h>

void	build_matrix_transform_pl(t_tuple coor, t_tuple normal, t_obj *o)
{
	t_matrix4	trans;
	t_matrix4	rotat_x;
	t_matrix4	rotat_z;
	t_matrix4	mult;

	translation(coor.x, coor.y, coor.z, trans);
	rotation_z(atan2(normal.x, normal.y), rotat_z);
	rotation_x(-asin(normal.z), rotat_x);
	matrix4_multiplication(rotat_z, rotat_x, mult);
	matrix4_multiplication(trans, mult, o->transform);
	matrix4_inverse(o->transform, o->inverse_transform);
}

int	make_pl(t_obj *o, char *str)
{
	t_tuple		coor;
	t_tuple		normal_vec;
	t_rgb		color;
	char		**data;

	data = ft_split(str, ' ');
	if (!data)
		return (1);
	*o = shape(PLANE);
	if (size_of_split(data) != 4 || get_coord(data[1], &coor)
		|| get_vector_coord(data[2], &normal_vec) || get_rgb(data[3], &color))
	{
		ft_free_split(data);
		return (1);
	}
	o->material.color = color;
	build_matrix_transform_pl(coor, normal_vec, o);
	ft_free_split(data);
	return (0);
}
