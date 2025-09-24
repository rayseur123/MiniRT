/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tuple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:02:42 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 13:45:29 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

t_tuple	set_vector(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 0;
	return (tuple);
}

t_tuple	set_point(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = 1;
	return (tuple);
}
