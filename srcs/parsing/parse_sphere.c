/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:25:19 by njooris           #+#    #+#             */
/*   Updated: 2025/10/29 16:38:10 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	make_sp(t_obj *o, char *str)
{
	t_tuple		coor;
	double		radius;
	char		**data;

	data = ft_split(str, ' ');
	if (!data)
		return (1);
	*o = shape(SPHERE);
	if (size_of_split(data) != 4 || get_coord(data[1], &coor)
		|| check_is_digit_str(data[2]))
	{
		ft_free_split(data);
		return (1);
	}
	radius = get_radius(data[2]);
	build_matrix_transform_sp(coor, radius, o);
	if (get_rgb(data[3], &o->material.color))
	{
		ft_free_split(data);
		return (1);
	}
	ft_free_split(data);
	return (0);
}
