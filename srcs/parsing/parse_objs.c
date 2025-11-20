/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:14:01 by njooris           #+#    #+#             */
/*   Updated: 2025/11/20 14:24:10 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_error.h"
#include "libft.h"
#include "parsing.h"

int	build_objs(char *line_obj, t_world *world, int *count_obj)
{
	if (!ft_strncmp(line_obj, "sp", 2))
	{
		if (make_sp(&world->obj[*count_obj], line_obj))
			return (1);
		*count_obj += 1;
	}
	if (!ft_strncmp(line_obj, "pl", 2))
	{
		if (make_pl(&world->obj[*count_obj], line_obj))
			return (1);
		*count_obj += 1;
	}
	if (!ft_strncmp(line_obj, "cy", 2))
	{
		if (make_cy(&world->obj[*count_obj], line_obj))
			return (1);
		*count_obj += 1;
	}
	return (0);
}

int	make_objs(t_world *world, t_camera *c, int fd)
{
	int			count_obj;
	int			count_light;
	char		*line_obj;

	line_obj = next_obj(fd);
	if (!line_obj)
		return (print_error(MALLOC_ERROR));
	count_obj = 0;
	count_light = 0;
	while (line_obj)
	{
		if (build_objs(line_obj, world, &count_obj)
			|| (build_light(line_obj, world, &count_light))
			|| (line_obj[0] == 'C' && make_cam(c, line_obj))
			|| (line_obj[0] == 'A' && make_ambient(line_obj, world)))
		{
			free(line_obj);
			return (1);
		}
		free(line_obj);
		line_obj = next_obj(fd);
	}
	return (0);
}
