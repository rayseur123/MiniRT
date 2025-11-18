/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:53:06 by njooris           #+#    #+#             */
/*   Updated: 2025/11/18 10:10:08 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_error.h"
#include "libft.h"
#include "parsing.h"

int	alloc_world(t_world *world)
{
	world->obj = malloc(sizeof(t_obj) * world->nb_obj);
	if (!world->obj)
		return (print_error(MALLOC_ERROR));
	world->light = malloc(sizeof(t_light) * world->nb_light);
	if (!world->light)
	{
		free(world->obj);
		return (print_error(MALLOC_ERROR));
	}
	return (0);
}

int	check_count_cap(int count_ambient, int count_light, int count_cam, int fd)
{
	if (close(fd) == -1)
		return (print_error(CLOSE_ERROR));
	if (count_ambient < 1 || count_cam < 1 || count_light < 1)
		return (print_error(MISS_CAP_ERROR));
	if (count_ambient > 1 || count_cam > 1 || count_light > 1)
		return (print_error(DOUBLE_CAP_ERROR));
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
		return (print_error(FD_ERROR));
	if (fd == 1)
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
	return (check_count_cap(count_ambient, count_light, count_cam, fd));
}

int	parsing(char *str, t_world *world, t_camera *c)
{
	const int	fd = open_rt_file(str);

	if (fd < 0)
		return (1);
	if (check_cap(str))
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
	if (close(fd) == -1)
		return (print_error(CLOSE_ERROR));
	return (0);
}
