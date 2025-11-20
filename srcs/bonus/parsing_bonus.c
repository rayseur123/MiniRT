/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:20:51 by njooris           #+#    #+#             */
/*   Updated: 2025/11/20 14:26:18 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_error.h"
#include "libft.h"
#include "parsing.h"

int	count_obj_and_light(char *str, t_world *w)
{
	char		*line;
	const int	fd = open_rt_file(str);

	if (fd == -1)
		return (print_error(FD_ERROR));
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "pl", 2) || !ft_strncmp(line, "cy", 2)
			|| !ft_strncmp(line, "sp", 2))
			w->nb_obj++;
		if (line[0] == 'L' || line[0] == 'l')
			w->nb_light++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (print_error(CLOSE_ERROR));
	return (0);
}

char	*next_obj(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (!ft_strncmp(str, "pl", 2) || !ft_strncmp(str, "cy", 2)
			|| !ft_strncmp(str, "sp", 2) || str[0] == 'L' || str[0] == 'C'
			|| str[0] == 'l' || str[0] == 'A')
			return (str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (str);
}

int	build_light(char *line_obj, t_world *world, int *count_light)
{
	static uint32_t	check_l;

	if (line_obj[0] == 'L' || line_obj[0] == 'l')
	{
		if (line_obj[0] == 'L' && check_l++)
			return (print_error(TO_MANY_LIGHT_ERROR));
		if (make_light(&world->light[*count_light], line_obj))
			return (1);
		*count_light += 1;
	}
	return (0);
}