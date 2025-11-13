/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:40:24 by njooris           #+#    #+#             */
/*   Updated: 2025/11/13 13:37:12 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include "parsing.h"
#include "camera.h"
#include "transform.h"
#include <stdio.h>
#include <math.h>
#include "minirt_error.h"

int	build_a_parse(t_world *world, char **data)
{
	t_rgb	color;
	double	power;

	if (size_of_split(data) != 3)
		return (print_error(PARAMETER_NUMBER_ERROR));
	if (ft_strlen(data[0]) != 1)
		return (print_error(ARGUMENT_ERROR));
	power = ft_atod(data[1]);
	if (get_rgb(data[2], &color))
		return (1);
	world->ambient = rgb_multiplication_scalar(color, power);
	return (0);
}

int	make_ambient(char *str, t_world *world)
{
	char	**data;

	data = ft_split(str, ' ');
	if (!data)
		return (print_error(MALLOC_ERROR));
	if (build_a_parse(world, data))
	{
		ft_free_split(data);
		return (1);
	}
	ft_free_split(data);
	return (0);
}
