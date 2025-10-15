/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:53:06 by njooris           #+#    #+#             */
/*   Updated: 2025/10/15 11:03:44 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "parsing.h"
#include "world.h"
#include "sphere.h"
#include "transform.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	count_obj(char *str)
{
	int		count;
	char	*line;
	const int	fd = open_rt_file(str);

	if (fd == -1)
		return (1);
	count = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (count);
	}
	count++;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "pl", 2) || !ft_strncmp(line, "cy", 2)
			|| !ft_strncmp(line, "sp", 2))
			count++;
		free(line);
	}
	close(fd);
	return (count);
}

int	count_light(char *str)
{
	int		count;
	char	*line;
	const int	fd = open_rt_file(str);
	
	if (fd == -1)
		return (1);
	count = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (count);
	}
	count++;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "L", 1))
			count++;
		free(line);
	}
	close(fd);
	return (count);
}

int	alloc_world(t_world *world)
{
	world->obj = malloc(sizeof(t_obj) * world->nb_obj);
	if (!world->obj)
		return (1);
	world->light = malloc(sizeof(t_obj) * world->nb_light);
	if (!world->light)
	{
		free(world->obj);
		return (1);
	}
	return (0);
}

char	*next_obj(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while(str)
	{
		if (!ft_strncmp(str, "pl", 2) || !ft_strncmp(str, "cy", 2)
			|| !ft_strncmp(str, "sp", 2))
			return (str);
		str = get_next_line(fd);
		free(str);
	}
	return (str);
}

int	get_coord(char *str, t_tuple *point)
{
	char	**coord;

	coord = ft_split(str, ',');
	if (!coord)
		return (1);
	*point = set_point(ft_atod(coord[0]), ft_atod(coord[1]), ft_atod(coord[2]));
	free_split(coord);
	return (0);
}

double	get_diameter(char *str)
{
	return (ft_atod(str));	
}

int	get_rgb(char *str, t_rgb *rgb)
{
	char 	**rgb_split;

	rgb_split = ft_split(str, ',');
	if (!rgb_split)
		return (1);
	rgb->r = atoi(rgb_split[0]) / 255;
	rgb->g = atoi(rgb_split[1]) / 255;
	rgb->b = atoi(rgb_split[2]) / 255;
	free_split(rgb_split);
	return (0);
}

int	make_sp(t_world *w, char *str, int count_obj)
{
	t_tuple	coor;
	double	diameter;
	char	**data;
	t_matrix4	trans;
	t_matrix4	scale;

	data = ft_split(str, ' ');
	if (!data)
		return (1);
	w->obj[count_obj] = sphere();
	if (get_coord(data[1], &coor))
	{
		free_split(data);
		return (1);
	}
	translation(coor.x, coor.y, coor.z, trans);
	diameter = get_diameter(data[2]);
	scaling(diameter, diameter, diameter, scale);
	matrix4_multiplication(scale, trans, w->obj[count_obj].transform);
	matrix4_inverse(w->obj[count_obj].transform, w->obj[count_obj].inverse_transform);
	if (get_rgb(data[3], &w->obj[count_obj].material.color))
	{
		free_split(data);
		return (1);
	}
	return (0);
}

int	make_objs(char *str, t_world *world)
{
	int			count_obj;
	const int	fd = open_rt_file(str);
	char 		*line_obj;

	if (fd == -1)
		return (1);
	line_obj = next_obj(fd);
	count_obj = 0;
	while (line_obj)
	{
		if (!ft_strncmp(line_obj, "sp", 2))
			make_sp(world, line_obj, count_obj++);
		line_obj = next_obj(fd);
	}
	close(fd);
	return (0);
}

void	display_matrix(t_matrix4 m)
{
	int i = 0;

	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			printf("|%f|", m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	parsing(char *str, t_world *world)
{
	// check file is good
	world->nb_obj = count_obj(str);
	world->nb_light = count_light(str);

	if (alloc_world(world))
		return (1);
	make_objs(str, world);
	return (0);
}
