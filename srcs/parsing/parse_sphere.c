/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:25:19 by njooris           #+#    #+#             */
/*   Updated: 2025/11/10 14:05:46 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parsing.h"
#include "sphere.h"
#include "libft.h"
#include "transform.h"

void	build_matrix_transform_sp(t_tuple coor, double radius, t_obj *o)
{
	t_matrix4	trans;
	t_matrix4	scale;

	translation(coor.x, coor.y, coor.z, trans);
	scaling(radius, radius, radius, scale);
	matrix4_multiplication(trans, scale, o->transform);
	matrix4_inverse(o->transform, o->inverse_transform);
}

int	build_sp_parse(t_obj *o, char **data)
{
	double	radius;
	t_tuple	coor;

	if (size_of_split(data) != 4)
		return (print_error(PARAMETER_NUMBER_ERROR));
	if (ft_strlen(data[0]) != 2)
		return (print_error(ARGUMENT_ERROR));
	if (get_coord(data[1], &coor) || check_is_digit_str(data[2]))
		return (1);
	radius = get_radius(data[2]);
	build_matrix_transform_sp(coor, radius, o);
	if (get_rgb(data[3], &o->material.color))
		return (1);
	return (0);
}

int	make_sp(t_obj *o, char *str)
{
	char		**data;

	data = ft_split(str, ' ');
	if (!data)
		return (print_error(MALLOC_ERROR));
	*o = shape(SPHERE);
	if (build_sp_parse(o, data))
	{
		ft_free_split(data);
		return (1);
	}
	ft_free_split(data);
	return (0);
}
