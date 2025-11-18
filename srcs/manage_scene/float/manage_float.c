/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:00:31 by njooris           #+#    #+#             */
/*   Updated: 2025/11/13 14:55:17 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <math.h>

int	double_is_equal(double x, double y)
{
	return (fabs(x - y) < EPSILON);
}
