/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:25:19 by njooris           #+#    #+#             */
/*   Updated: 2025/11/10 14:06:35 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "sphere.h"
#include "libft.h"
#include "transform.h"
#include <math.h>
#include "error.h"

void	build_matrix_transform_cy(double r, t_tuple coor, t_tuple n, t_obj *o)
{
	t_matrix4	trans;
	t_matrix4	rotat_x;
	t_matrix4	rotat_z;
	t_matrix4	mult;
	t_matrix4	scale;

	scaling(r, r, r, scale);
	rotation_z(atan2(n.x, n.y), rotat_z);
	rotation_x(-asin(n.z), rotat_x);
	translation(coor.x, coor.y, coor.z, trans);
	matrix4_multiplication(rotat_z, rotat_x, mult);
	matrix4_multiplication(mult, scale, rotat_z);
	matrix4_multiplication(trans, rotat_z, o->transform);
	matrix4_inverse(o->transform, o->inverse_transform);
}

int	build_cy_parse(t_obj *o, char **data)
{
	t_tuple		coor;
	t_tuple		normal_vec;
	double		radius;
	double		height;

	if (size_of_split(data) != 6)
		return (print_error(PARAMETER_NUMBER_ERROR));
	if (ft_strlen(data[0]) != 2)
		return (print_error(ARGUMENT_ERROR));
	if (get_coord(data[1], &coor) || get_vector_coord(data[2], &normal_vec)
		|| get_rgb(data[5], &o->material.color))
		return (1);
	radius = get_radius(data[3]);
	height = ft_atod(data[4]) / 2;
	o->min = -height;
	o->max = height;
	build_matrix_transform_cy(radius, coor, normal_vec, o);
	return (0);
}

int	make_cy(t_obj *o, char *str)
{
	char		**data;

	data = ft_split(str, ' ');
	if (!data)
		return (print_error(MALLOC_ERROR));
	*o = shape(CYLINDER);
	if (build_cy_parse(o, data))
	{
		ft_free_split(data);
		return (1);
	}
	ft_free_split(data);
	return (0);
}
