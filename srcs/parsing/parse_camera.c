/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:49:45 by njooris           #+#    #+#             */
/*   Updated: 2025/10/21 16:13:29 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuple.h"
#include "libft.h"
#include "transform.h"
#include "matrix.h"
#include "parsing.h"

int	make_cam(t_camera *c, char *str)
{
	char		**data;
	t_tuple		from;
	t_tuple		to;

	data = ft_split(str, ' ');
	if (!data)
		return (1);
	if (size_of_split(data) != 4 || get_coord(data[1], &from))
	{
		ft_free_split(data);
		return (1);
	}
	if (get_coord(data[2], &to))
	{
		ft_free_split(data);
		return (1);
	}
	*c = camera(WIDTH_CANVA, HEIGHT_CANVA, (ft_atod(data[3]) * M_PI) / 180.0);
	to = tuple_addition(from, to);
	to.w = 1;
	view_transform(from, to,
		set_vector(0, 1, 0), c->transform);
	matrix4_inverse(c->transform, c->inverse_transform);
	return (0);
}
