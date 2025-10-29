/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:53:06 by njooris           #+#    #+#             */
/*   Updated: 2025/10/29 13:38:43 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "parsing.h"
#include "world.h"
#include "light.h"
#include "transform.h"

int	alloc_world(t_world *world)
{
	world->obj = malloc(sizeof(t_obj) * world->nb_obj);
	if (!world->obj)
		return (1);
	world->light = malloc(sizeof(t_light) * world->nb_light);
	if (!world->light)
	{
		free(world->obj);
		return (1);
	}
	return (0);
}

int	get_coord(char *str, t_tuple *point)
{
	char	**coord;

	coord = ft_split(str, ',');
	if (!coord)
		return (1);
	if (size_of_split(coord) != 3 || check_is_digit_str(coord[0])
		|| check_is_digit_str(coord[1]) || check_is_digit_str(coord[2]))
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
		return (1);
	if (size_of_split(coord) != 3 || check_is_digit_str(coord[0])
		|| check_is_digit_str(coord[1]) || check_is_digit_str(coord[2]))
	{
		ft_free_split(coord);
		return (1);
	}
	*vector = set_vector(ft_atod(coord[0]), ft_atod(coord[1]), ft_atod(coord[2]));
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
		return (1);
	if (size_of_split(rgb_split) != 3)
	{
		ft_free_split(rgb_split);
		return (1);
	}
	rgb->r = (double)ft_atoi(rgb_split[0]) / 255;
	rgb->g = (double)ft_atoi(rgb_split[1]) / 255;
	rgb->b = (double)ft_atoi(rgb_split[2]) / 255;
	ft_free_split(rgb_split);
	return (0);
}

int	parsing(char *str, t_world *world, t_camera *c)
{
	const int	fd = open_rt_file(str);

	if (fd == -1)
		return (1);
	if (count_obj_and_light(str, world))
		return (1);
	if (alloc_world(world))
		return (1);
	return (make_objs(world, c, fd));
}
