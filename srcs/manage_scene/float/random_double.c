/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:23:06 by njooris           #+#    #+#             */
/*   Updated: 2025/10/24 13:12:04 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

double	random_xor(uint32_t *seed)
{
	*seed ^= (*seed << 13);
	*seed ^= *seed >> 17;
	*seed ^= *seed << 5;
	return (((double)*seed / (UINT32_MAX / 2.0)) - 1.0);
}
