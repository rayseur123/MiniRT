/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:14:01 by njooris           #+#    #+#             */
/*   Updated: 2025/10/29 16:57:52 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include "parsing.h"
#include "camera.h"
#include "transform.h"
#include <stdio.h>
#include <math.h>

int	count_obj_and_light(char *str, t_world *w)
{
	char		*line;
	const int	fd = open_rt_file(str);

	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (1);
	}
	while (line)
	{
		if (!ft_strncmp(line, "pl", 2) || !ft_strncmp(line, "cy", 2)
			|| !ft_strncmp(line, "sp", 2))
			w->nb_obj++;
		if (line[0] == 'L')
			w->nb_light++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	return (0);
}

char	*next_obj(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (!ft_strncmp(str, "pl", 2) || !ft_strncmp(str, "cy", 2)
			|| !ft_strncmp(str, "sp", 2) || str[0] == 'L' || str[0] == 'C')
			return (str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (str);
}

int	free_line(char *line)
{
	free(line);
	return (1);
}

int	build_objs(char *line_obj, t_world *world, int *count_obj)
{
	if (!ft_strncmp(line_obj, "sp", 2))
	{
		if (make_sp(&world->obj[*count_obj], line_obj))
			return (free_line(line_obj));
		*count_obj += 1;
	}
	if (!ft_strncmp(line_obj, "pl", 2))
	{
		if (make_pl(&world->obj[*count_obj], line_obj))
			return (free_line(line_obj));
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
		return (1);
	count_obj = 0;
	count_light = 0;
	while (line_obj)
	{
		if (build_objs(line_obj, world, &count_obj))
			return (1);
		if (line_obj[0] == 'L'
			&& make_light(&world->light[count_light++], line_obj))
			return (free_line(line_obj));
		if (line_obj[0] == 'C'
			&& make_cam(c, line_obj))
			return (free_line(line_obj));
		free_line(line_obj);
		line_obj = next_obj(fd);
	}
	close(fd);
	return (0);
}
