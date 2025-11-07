/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:53:06 by njooris           #+#    #+#             */
/*   Updated: 2025/11/07 11:54:01 by njooris          ###   ########.fr       */
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

int	check_cap(char *str)
{
	char		*line;
	const int	fd = open_rt_file(str);
	int			count_ambient;
	int			count_light;
	int			count_cam;

	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	count_ambient = 0;
	count_light = 0;
	count_cam = 0;
	while (line)
	{
		if ((line[0] == 'A' && count_ambient++)
			|| (line[0] == 'C' && count_cam++)
			|| (line[0] == 'L' && count_light++))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count_ambient != 1 || count_cam != 1 || count_light != 1)
		return (1);
	return (0);
}

int	parsing(char *str, t_world *world, t_camera *c)
{
	const int	fd = open_rt_file(str);

	if (fd == -1)
		return (1);
	if (check_cap(str) || count_obj_and_light(str, world))
		return (1);
	if (alloc_world(world))
		return (1);
	if (make_objs(world, c, fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
