/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:44:48 by njooris           #+#    #+#             */
/*   Updated: 2025/09/29 10:06:49 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	test_ray_position(void)
{
	t_ray ray;

	ray.origin = set_point(2, 3, 4);
	ray.direction = set_vector(1, 0, 0);
	if (!check_equal_tuples(position(ray, 0.0), set_point(2, 3, 4)))
		return (1);
	if (!check_equal_tuples(position(ray, 1.0), set_point(3, 3, 4)))
		return (1);
	if (!check_equal_tuples(position(ray, -1.0), set_point(1, 3, 4)))
		return (1);
	if (!check_equal_tuples(position(ray, 2.5), set_point(4.5, 3, 4)))
		return (1);
	return (0);
}