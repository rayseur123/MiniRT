/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:40:24 by njooris           #+#    #+#             */
/*   Updated: 2025/11/05 14:41:19 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include "parsing.h"
#include "camera.h"
#include "transform.h"
#include <stdio.h>
#include <math.h>

int	make_ambient(char *str, t_world *world)
{
	char	**data;
	t_rgb	color;
	double	power;

	data = ft_split(str, ' ');
	if (size_of_split(data) != 2)
	{
		ft_free_split(data);
		return (1);
	}
	power = ft_atod(data[0]);
	if (get_rgb(data[1], &color))
	{
		ft_free_split(data);
		return (1);
	}
	world->ambient = rgb_multiplication_scalar(color, power);
	ft_free_split(data);
	return (0);
}
