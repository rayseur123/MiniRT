/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_tuple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:04:30 by njooris           #+#    #+#             */
/*   Updated: 2025/11/18 10:36:12 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

int	check_equal_tuples(t_tuple tuple1, t_tuple tuple2)
{
	return ((double_is_equal(tuple1.x, tuple2.x)
			&& double_is_equal(tuple1.y, tuple2.y)
			&& double_is_equal(tuple1.z, tuple2.z)));
}
