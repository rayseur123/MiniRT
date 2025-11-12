/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:05:29 by dernst            #+#    #+#             */
/*   Updated: 2025/11/10 16:07:43 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int	quicksort(int *list, int start, int end)
{
	int pivot;
	int i;

	pivot = list[end];
	i = start - 1;
	while (start < end)
	{
		if (list[start] < pivot)
		{
			i++;
			swap(&list[i], &list[start]);
		}
		start++;
	}
	swap(&list[i + 1], &list[end]);
	return (i + 1);
}

void	recursive(int *list, int start, int end)
{
	int	index_pivot;
	if (start < end)
	{
		index_pivot = quicksort(list, start, end);
		recursive(list,start, index_pivot - 1);
		recursive(list, index_pivot + 1, end);
	}
}

int main(void)
{
	int	*list;

	list = malloc(10 * sizeof(int));
	list[0] = 3;
	list[1] = 2;
	list[2] = 0;
	list[3] = 5;
	list[4] = 1;
	list[5] = 8;
	list[6] = 7;
	list[7] = 6;
	list[8] = 9;
	list[9] = 4;

	recursive(list, 0, 9);
}