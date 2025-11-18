/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:49:45 by njooris           #+#    #+#             */
/*   Updated: 2025/11/13 13:37:12 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "minirt_error.h"

int	build_cm_parse(t_camera *c, char **data)
{
	t_tuple		from;
	t_tuple		to;

	if (size_of_split(data) != 4)
		return (print_error(PARAMETER_NUMBER_ERROR));
	if (ft_strlen(data[0]) != 1)
		return (print_error(ARGUMENT_ERROR));
	if (get_coord(data[1], &from))
		return (1);
	if (get_coord(data[2], &to))
		return (1);
	*c = camera(WIDTH_CANVA, HEIGHT_CANVA, (ft_atod(data[3]) * M_PI) / 180.0);
	to = tuple_addition(from, to);
	to.w = 1;
	view_transform(from, to, set_vector(0, 1, 0), c->transform);
	matrix4_inverse(c->transform, c->inverse_transform);
	return (0);
}

int	make_cam(t_camera *c, char *str)
{
	char		**data;

	data = ft_split(str, ' ');
	if (!data)
		return (print_error(MALLOC_ERROR));
	if (build_cm_parse(c, data))
	{
		ft_free_split(data);
		return (1);
	}
	ft_free_split(data);
	return (0);
}
