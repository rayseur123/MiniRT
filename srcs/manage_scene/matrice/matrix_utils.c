/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:15:49 by njooris           #+#    #+#             */
/*   Updated: 2025/10/15 11:33:05 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "libft.h"

void	display_matrix(t_matrix4 m)
{
	int i = 0;

	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			ft_printf("|%f|", m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}