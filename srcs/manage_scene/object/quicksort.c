/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:05:29 by dernst            #+#    #+#             */
/*   Updated: 2025/11/13 09:22:34 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	swap(t_inter *a, t_inter *b)
{
	t_inter	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	quicksort(t_inter *inters, int start, int end)
{
	double	pivot;
	int		i;

	pivot = inters[end].range;
	i = start - 1;
	while (start < end)
	{
		if (inters[start].range < pivot)
		{
			i++;
			swap(&inters[i], &inters[start]);
		}
		start++;
	}
	swap(&inters[i + 1], &inters[end]);
	return (i + 1);
}

void	recursive(t_inter *inters, int start, int end)
{
	int	index_pivot;

	if (start < end)
	{
		index_pivot = quicksort(inters, start, end);
		recursive(inters, start, index_pivot - 1);
		recursive(inters, index_pivot + 1, end);
	}
}
