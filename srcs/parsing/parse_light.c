/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:49:45 by njooris           #+#    #+#             */
/*   Updated: 2025/11/06 11:25:39 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuple.h"
#include "libft.h"
#include "transform.h"
#include "matrix.h"
#include "parsing.h"

int	make_light(t_light *l, char *str)
{
	double		bright;
	char		**data;

	data = ft_split(str, ' ');
	if (!data)
		return (1);
	if (size_of_split(data) != 4 || ft_strlen(data[0]) != 1 || get_coord(data[1], &l->position))
	{
		ft_free_split(data);
		return (1);
	}
	bright = ft_atod(data[2]);
	if (get_rgb(data[3], &l->intensity))
	{
		ft_free_split(data);
		return (1);
	}
	l->intensity = rgb_multiplication_scalar(l->intensity, bright);
	ft_free_split(data);
	return (0);
}
