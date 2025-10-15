/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:25:19 by njooris           #+#    #+#             */
/*   Updated: 2025/10/15 13:37:38 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "sphere.h"
#include "libft.h"
#include "transform.h"

int	make_sp(t_obj *o, char *str)
{
	t_tuple		coor;
	double		diameter;
	char		**data;
	t_matrix4	trans;
	t_matrix4	scale;

	data = ft_split(str, ' ');
	if (!data)
		return (1);
	*o = sphere();
	if (get_coord(data[1], &coor))
	{
		ft_free_split(data);
		return (1);
	}
	translation(coor.x, coor.y, coor.z, trans);
	diameter = get_diameter(data[2]);
	scaling(diameter, diameter, diameter, scale);
	matrix4_multiplication(trans, scale, o->transform);
	matrix4_inverse(o->transform, o->inverse_transform);
	if (get_rgb(data[3], &o->material.color))
	{
		ft_free_split(data);
		return (1);
	}
	return (0);
}