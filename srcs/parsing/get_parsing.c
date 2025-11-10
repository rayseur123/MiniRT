/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:39:17 by njooris           #+#    #+#             */
/*   Updated: 2025/11/10 13:20:44 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "parsing.h"
#include "world.h"
#include "light.h"
#include "transform.h"
#include "error.h"

int	get_coord(char *str, t_tuple *point)
{
	char	**coord;

	coord = ft_split(str, ',');
	if (!coord)
		return (print_error(MALLOC_ERROR));
	if (size_of_split(coord) != 3)
		return (print_error(COORD_NUMBER_ERROR));
	if (check_is_digit_str(coord[0]) || check_is_digit_str(coord[1])
		|| check_is_digit_str(coord[2]))
	{
		ft_free_split(coord);
		return (1);
	}
	*point = set_point(ft_atod(coord[0]), ft_atod(coord[1]), ft_atod(coord[2]));
	ft_free_split(coord);
	return (0);
}

int	get_vector_coord(char *str, t_tuple *vector)
{
	char	**coord;

	coord = ft_split(str, ',');
	if (!coord)
		return (print_error(MALLOC_ERROR));
	if (size_of_split(coord) != 3)
		return (print_error(COORD_NUMBER_ERROR));
	if (check_is_digit_str(coord[0]) || check_is_digit_str(coord[1])
		|| check_is_digit_str(coord[2]))
	{
		ft_free_split(coord);
		return (1);
	}
	*vector = set_vector(ft_atod(coord[0]),
			ft_atod(coord[1]), ft_atod(coord[2]));
	*vector = tuple_normalization(*vector);
	ft_free_split(coord);
	return (0);
}

double	get_radius(char *str)
{
	return (ft_atod(str) / 2);
}

int	get_rgb(char *str, t_rgb *rgb)
{
	char	**rgb_split;

	rgb_split = ft_split(str, ',');
	if (!rgb_split)
		return (print_error(MALLOC_ERROR));
	if (size_of_split(rgb_split) != 3)
	{
		ft_free_split(rgb_split);
		return (print_error(RGB_NUMBER_ERROR));
	}
	rgb->r = (double)ft_atoi(rgb_split[0]) / 255;
	rgb->g = (double)ft_atoi(rgb_split[1]) / 255;
	rgb->b = (double)ft_atoi(rgb_split[2]) / 255;
	ft_free_split(rgb_split);
	return (0);
}
