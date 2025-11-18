/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:49:45 by njooris           #+#    #+#             */
/*   Updated: 2025/11/13 13:36:56 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "minirt_error.h"

int	build_l_parse(t_light *l, char **data)
{
	double		bright;

	if (size_of_split(data) != 4)
		return (print_error(PARAMETER_NUMBER_ERROR));
	if (ft_strlen(data[0]) != 1)
		return (print_error(ARGUMENT_ERROR));
	if (get_coord(data[1], &l->position))
		return (1);
	bright = ft_atod(data[2]);
	if (get_rgb(data[3], &l->intensity))
		return (1);
	l->intensity = rgb_multiplication_scalar(l->intensity, bright);
	return (0);
}

int	make_light(t_light *l, char *str)
{
	char		**data;

	data = ft_split(str, ' ');
	if (!data)
		return (print_error(MALLOC_ERROR));
	if (build_l_parse(l, data))
	{
		ft_free_split(data);
		return (1);
	}
	ft_free_split(data);
	return (0);
}
