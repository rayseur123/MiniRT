/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:53:06 by njooris           #+#    #+#             */
/*   Updated: 2025/11/05 14:42:52 by njooris          ###   ########.fr       */
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

int	parsing(char *str, t_world *world, t_camera *c)
{
	const int	fd = open_rt_file(str);

	if (fd == -1)
		return (1);
	if (count_obj_and_light(str, world))
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
